#include<bits/stdc++.h>
using namespace std;
const long long M=988244353;
long long n,m,ans=1,cnt;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.ans","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        ans=(ans*i)%M;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='0')
            cnt++;
    if(cnt>n-m)printf("0");
    else printf("%lld",ans);
    return 0;
}
