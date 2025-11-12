#include <bits/stdc++.h>
using namespace std;
int t,n,sum;
int a[100010],b[100010],c[100010],f[100010];
void dfs(int step,int ans,int a1,int a2,int a3)
{
    //cout<<step-1<<" "<<ans<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
    if(step>n+1 || a1<0 || a2<0 || a3<0)
    {
        sum=max(sum,ans);
        return;
    }
        if(a1<n/2)
        {
            dfs(step+1,ans+a[step],a1+1,a2,a3);
            //ans-=a[step];
            //a1--;
        }
        if(a2<n/2)
        {
            //if(fa==1) step--;
            dfs(step+1,ans+b[step],a1,a2+1,a3);
            //ans-=b[step];
            //a2--;
        }
        if(a3<n/2)
        {
            //if(fb==1) step--;
            dfs(step+1,ans+c[step],a1,a2,a3+1);

        }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        int a1=0,a2=0,a3=0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        //memset(f,0,sizeof f);
        for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        dfs(1,0,a1,a2,a3);
        //cout<<endl;
        cout<<sum<<endl;
    }
}
