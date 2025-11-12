#include <bits/stdc++.h>
#define ll long long
#define el endl
using namespace std;
const ll N=1e6;
string s;
int a[N],ret=0;
void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++){
       if(s[i]>='0'&&s[i]<='9')
       {
           a[i]=s[i]-'0';
           ret++;
       }
    }
    sort(a,a+s.size(),greater<int>());
    for(int i=0;i<ret;i++){
        cout<<a[i];
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int  T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
