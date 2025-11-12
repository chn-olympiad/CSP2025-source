#include<bits/stdc++.h>
using namespace std;
int as,bs,cs;
int a[1000001],b[1000001],c[1000001],ans,n,al[1000001],bl[1000001],cl[1000001];
void dfs (int as,int bs,int l,int cs, int id,int sum)
{
    ans=max(ans,sum);
    if(id>n) return;
    if(as+1,bs,cs,l,id+1,sum+a[id]);
    if(as,bs+1,cs,l,id+1,sum+b[id]);
    if(as,bs,cs+1,l,id+1,sum+c[id]);
}
void slove()
{
    int n;
    cin>>n;
    int l=n/2;
    int ans=0;
    cout<<l<<" ";
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i]>>c[i];
        dfs(0,0,0,1,1,0);
        cout<<ans<<endl;


    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);
    int t;
    cin>>t;
    cout<<"l"<<endl;
    while(t--)
    {
        cin>>n;
        int l=n/2;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i]>>b[i]>>c[i];
            dfs(0,0,0,1,1,0);
            al[i]=(1,0,0,a[l])=b[i]=(0,1,0,b[i]),c[i]=(0,0,1,c[i]);

            for(int i=1;i<=n;++i)
            {
                int ax=0,bx=0,cx=0,ax1=0,ax2=0,bx1=0,bx2=0,cx1=0,cx2=0;

            }

        }
    }
    return 0;

}

