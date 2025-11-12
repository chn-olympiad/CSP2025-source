#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long l=s.length(),t=0;
    for(int i=0;i<l;i++) if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
    sort(a+1,a+1+t,cmp);
    for(int i=1;i<=t;i++){
        printf("%lld",a[i]);
    }
    return 0;
}
