#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e6+10;
LL a[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    LL t=0;
    for(LL i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-'0';
    }
    sort(a+1,a+t+1,cmp);
    for(LL i=1;i<=t;i++){
        cout<<a[i];
    }
    return 0;
}
