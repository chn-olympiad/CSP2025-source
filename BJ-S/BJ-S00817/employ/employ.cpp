#include <bits/stdc++.h>
using namespace std;
const int N=1005;
const int MOD=998244353;
int s[N],c[N];int n,m;
bool viss[N];
bool visp[N];
long long ans;
void dfs(int deep,int cnt,int n1)
{
    //cout<<deep;
    if(deep>=n1+1){
    //cout<<cnt<<endl;
        if(cnt==m) {
            ans++;
            //cout<<"good";
            ans%=MOD;
        }
        //cout<<cnt<<" ";
        return ;
    }
    //cout<<deep<<" " ;

        for(int j=1;j<=n1;++j)
        {
            if(c[j]<deep-cnt || visp[j]==1)
            {
                visp[j]=1;
                continue;
            }
            visp[j]=1;
            for(int i=1;i<=n1;++i)
            {
            if(viss[i]) continue;
            viss[i]=1;

            if(s[i]==0)
            {
                //cout<<1<<":"<<cnt<<endl;

                dfs(deep+1,cnt,n1);
            }
            if(s[i]==1)
            {
                //cout<<2<<":"<<cnt<<endl;
                dfs(deep+1,cnt+1,n1);

            }

            viss[i]=0;
        }
        visp[j]=0;
        }


    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    bool flag=1;
    string axx;
    cin>>axx;
    for(int i=0;i<axx.size();++i)
    {
        if(axx[i]=='0') s[i+1]=0;
        else s[i+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];

    }
    dfs(1,0,n);
    cout<<ans;
    return 0;
}
