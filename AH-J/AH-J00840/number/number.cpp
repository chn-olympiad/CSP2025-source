#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N];
int cnt=0;
string s;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<=s.size();i++){

    if(s[i]>='0'&&s[i]<='9'){
        a[++cnt]=s[i]-'0';
    }

}
sort(a+1,a+cnt+1,cmp);
for(int i=1;i<=cnt;i++){
    cout<<a[i];
}
    return 0;
}
