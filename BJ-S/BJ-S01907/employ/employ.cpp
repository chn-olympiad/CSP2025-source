#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
string s;
int a[100010],c[100010];
long long ans=0;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        a[i+1]=s[i]-'0';
    }
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    do
    {
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            if(a[i]==0 || i>=c[i]) continue;
            else cnt++;
        }
        if(cnt>=m) ans++;
    }while(next_permutation(c+1,c+n+1));
    cout<<ans%N<<endl;
    return 0;
}