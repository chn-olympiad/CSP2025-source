#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int x,y,z;
};
node c[200010];
int T,n,a[5],cnt[5];
long long ans;
bool cmp(node a,node b)
{

    return a.x>b.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(c,0,sizeof(c));
        cin>>n;
        ans=0;
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
        for(int i=1;i<=n;i++)
        {
            int cm=0,mx=0;
            for(int j=1;j<=3;j++)
            {
                cin>>a[j];
                if(a[mx]<=a[j])
                    cm=mx,mx=j;
                else if(a[cm]<=a[j])
                    cm=j;
            }
            c[i].x=a[mx]-a[cm];
            c[i].y=mx,c[i].z=cm;
            ans+=a[cm];
        }
        sort(c+1,c+1+n,cmp);
        int p=n/2;
        for(int i=1;i<=n;i++)
            if(cnt[c[i].y]<p)
                cnt[c[i].y]++,ans+=c[i].x;
            else
                cnt[c[i].z]++;
        cout<<ans<<endl;
    }
    return 0;
}
