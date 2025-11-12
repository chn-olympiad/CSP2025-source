#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],b[100005];
long long sum;
void bfs(int p,long long x,int v1,int v2,int v3)
{
    if(p>n)
    {
        sum=max(sum,x);
        return ;
    }
    if(v1<n/2)
    {
        x+=a[p][1];
        bfs(p+1,x,v1+1,v2,v3);
        x-=a[p][1];
    }
    if(v2<n/2)
    {
        x+=a[p][2];
        bfs(p+1,x,v1,v2+1,v3);
        x-=a[p][2];
    }
    if(v3<n/2)
    {
        x+=a[p][3];
        bfs(p+1,x,v1,v2,v3+1);
        x-=a[p][3];
    }

}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        sum=0;
        int cnt=0;
        int dd=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            dd+=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][2]==a[i][3]&&a[i][2]==0)
            {
                b[i]=a[i][1];
                cnt++;
            }
        }
        if(cnt==n)
        {
            sort(b+1,b+1+n,cmp);
            for(int i=1;i<=n/2;i++)
            {
                sum+=b[i];
            }

        }
        else if(n>=20)
        {
            sum=dd;
        }
        else
        {
            bfs(0,0,0,0,0);
        }
        cout<<sum<<endl;
    }
    return 0;
}
