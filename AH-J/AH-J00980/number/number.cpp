#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
string s;
ll a[N],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
    }
    sort(a+1,a+n+1);
    if(a[n]==0){printf("0");return 0;}
    for(ll i=n;i>=1;i--) printf("%lld",a[i]);
    return 0;
}
