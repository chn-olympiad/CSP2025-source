#include<bits/stdc++.h>
using namespace std;
int t,n,a[500005],b[500005],c[500005],m,aa,bb,cc;
long long an[500005],ans=0,anss=0;
bool f[3][500005];
void dfs(int x,int nums)
{
    if(aa>m||bb>m||cc>m)
    {
        return;
    }
    if(nums==x)
    {
        for(int i=1;i<=n;i++)
        {
            ans+=an[i];
        }
        //cout<<ans<<endl;
        if(ans>anss)
        {
            //cout<<an[1]<<" "<<an[2]<<" "<<an[3]<<" "<<an[4]<<endl;
            anss=ans;

        }
        ans=0;
    }
    for(int i=nums+1;i<=n;i++)
    {
        if(f[1][i]==0&&f[2][i]==0&&f[3][i]==0)
        {
            f[1][i]=1;
            an[i]=a[i];
            aa++;
            dfs(x,nums+1);
            aa--;
            f[1][i]=0;
        }
        if(f[1][i]==0&&f[2][i]==0&&f[3][i]==0)
        {
            f[2][i]=1;
            an[i]=b[i];
            bb++;
            dfs(x,nums+1);
            bb--;
            f[2][i]=0;
        }
        if(f[1][i]==0&&f[2][i]==0&&f[3][i]==0)
        {
            f[3][i]=1;
            an[i]=c[i];
            cc++;
            dfs(x,nums+1);
            cc--;
            f[3][i]=0;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        anss=0;
        cin>>n;
        m=n/2;
        int num1=0;
        int num2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]==0)
            {
                num1++;
            }
            if(c[i]==0)
            {
                num2++;
            }
        }

        if(num1==n&&num2==n)
        {
            sort(a+1,a+n+1);
            for(int i=1;i<=m;i++)
            {
                anss+=a[n+1-i];
            }
        }

        else
        {
            aa=0,bb=0,cc=0;
            dfs(n,0);
        }

        cout<<anss<<endl;
    }
    return 0;
}
