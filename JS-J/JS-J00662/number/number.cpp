#include<bits/stdc++.h>
using namespace std;
string s;
int shuzi=0;
const int maxn=1e6+10;
int a[maxn];
void f(char r){
    if(r>='0'&&r<='9'){
        a[shuzi]=r-'0';
        shuzi++;
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<=n-1;i++){
        f(s[i]);
    }
    sort(a,a+1+shuzi);
    for(int i=shuzi;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
