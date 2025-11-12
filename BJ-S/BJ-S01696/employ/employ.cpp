#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char ch;
bool f[1005];
int c[1005];
int a[1005];
long long ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>ch,f[i]=(ch=='1');
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
        for(int i=1;i<=n;i++)a[i]=i;
        do
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(f[i]&&i-1-cnt<c[a[i]])cnt++;
                //cout<<cnt<<' ';
            }
            //cout<<endl;
            if(cnt>=m)ans++;
            ans%=mod;
        }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
