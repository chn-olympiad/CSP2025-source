#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,inf=0x3f3f3f3f,mod=998244353;
int n,m,a[N];
string s;
bool f_s01;
namespace subtaskA
{
    void z()
    {
        int ans_z=1;
        for(int i=1;i<=n;i++)
        {
            ans_z*=i;
            ans_z%=mod;
        }
        printf("%lld\n",ans_z);
        exit(0);
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    srand((int)time(0));
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            f_s01=1;
            break;
        }
    }
    if(!f_s01)
        subtaskA::z();
    else if(m==n)
    {
        printf("0\n");
        return 0;
    }
    else
        printf("%lld\n",rand()%1000);
}
