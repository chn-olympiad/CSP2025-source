#include <bits/stdc++.h>
using namespace std;
string s;
int a[15],maxn,n;
void solve(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n=int(s[i])-48;
            a[n]++;
            maxn=max(maxn,n);
        }
    }
    for(int i=maxn;i>=0;i--){
        if(a[i]){
            for(int j=1;j<=a[i];j++) cout<<i;
        }
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    solve();
    return 0;
}
