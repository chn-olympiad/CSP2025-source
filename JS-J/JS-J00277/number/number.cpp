#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=20;
int t,q[maxn];
string s;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if((int)(s[i])>=48&&(int)(s[i])<=57){
            q[(int)(s[i]-48)]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<q[i];j++){
            printf("%lld",i);
        }
    }
    return 0;
}
