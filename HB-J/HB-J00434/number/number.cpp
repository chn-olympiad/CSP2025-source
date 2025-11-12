#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10000005];
long long cnt=0;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(long long i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
}
