#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;

long long c[600];

int main(void)
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    long long ans=1;
    cout<<n<<endl;
    for(long long i=2;i<=n-4;i++)ans=ans*i%P;
    cout<<ans%P;
    return 0;
}
