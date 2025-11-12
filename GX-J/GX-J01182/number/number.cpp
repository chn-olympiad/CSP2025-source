#include<bits/stdc++.h>
using namespace std;
long long a[1000009],cnt;
string s;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++cnt]=s[i]-'0';
            }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        printf("%lld",a[i]);
    }
    return 0;
}
