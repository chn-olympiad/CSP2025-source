#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct member
{
    int x,y,z,x1,x2,x3;
}a[N];
int T,n;
long long ans=0,sumx=0,sumy=0,sumz=0;
bool cmp1(member a,member b)
{
    return a.x>b.x;
}
bool cmp2(member a,member b)
{
    return a.y>b.y;
}
bool cmp3(member a,member b)
{
    return a.z>b.z;
}
void dfs(int pos,int sumX,int sumY,int cnt)
{
    if(cnt>=n/2)
    {
        ans=max(ans,sumX+sumy-sumY);
        return;
    }
    for(int i=pos+1;i<=n;i++)
    {
        dfs(i,sumX+a[i].x,sumY+a[i].y,cnt+1);
    }
}
void dfs2(int pos,long long sumX,long long sumY,long long sumZ,int cntx,int cnty,int cntz)
{
	//cout<<" "<<pos<<" "<<sumX<<" "<<sumY<<" "<<sumZ<<" "<<cntx<<" "<<cnty<<" "<<cntz<<"\n";
    if(pos>=n)
    {
        ans=max(ans,sumX+sumY+sumZ);
        return;
    }
    if(cntx<n/2)
		dfs2(pos+1,sumX+a[pos+1].x,sumY,sumZ,cntx+1,cnty,cntz);
	if(cnty<n/2)
		dfs2(pos+1,sumX,sumY+a[pos+1].y,sumZ,cntx,cnty+1,cntz);
	if(cntz<n/2)
		dfs2(pos+1,sumX,sumY,sumZ+a[pos+1].z,cntx,cnty,cntz+1);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=0,sumx=0,sumy=0,sumz=0;
        bool flag1=true,flag2=true,flag3=true,flag4=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].x1=min({a[i].x,a[i].y,a[i].z});
            a[i].x3=max({a[i].x,a[i].y,a[i].z});
            a[i].x2=a[i].x+a[i].y+a[i].z-a[i].x1-a[i].x3;
            sumx+=a[i].x,sumy+=a[i].y,sumz+=a[i].z;
            if(a[i].y!=0||a[i].z!=0) flag1=false;// yz=0
            if(a[i].x!=0||a[i].z!=0) flag3=false;//x z=0
            if(a[i].x!=0||a[i].y!=0) flag4=false;//xy =0
            if(a[i].z!=0) flag2=false;
        }
        //cout<<flag1<<" "<<flag2<<"\n";
        if(flag1==true)
        {
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i].x;
            }
            cout<<ans<<"\n";
        }
        else if(flag3==true)
        {
			sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i].y;
            }
            cout<<ans<<"\n";
		}
		else if(flag4==true)
		{
			sort(a+1,a+n+1,cmp3);
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i].z;
            }
            cout<<ans<<"\n";
		}
        else if(flag2==true)
        {
			for(int i=1;i<=n/2;i++)
            {
                dfs(i,a[i].x,a[i].y,1);
            }
            cout<<ans<<"\n";
        }
        else if(n<=30)
        {
            dfs2(0,0,0,0,0,0,0);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
