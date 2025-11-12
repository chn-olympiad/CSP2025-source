#include<bits/stdc++.h>
using namespace std;
#define mod 988244353
long long c[100005];
long long qui(int x){
    long long p=1;
    for(int i=2;i<=x;i++) p=p*i%mod;
    return p;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='1') sum++;
    }
    cout<<qui(sum)/(qui(m)*qui(sum-m))%mod;
    return 0;
}
