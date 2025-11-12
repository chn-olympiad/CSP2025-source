#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[1000005];
int n;
void solve(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[i]=s[i]-'0';
            s1+=s[i];
        }
    }
    n=s1.size();
    if(n==s.size()){
        sort(a,a+n);
        for(int i=n-1;i>=0;i--){
            cout<<a[i];
        }
    }
    else{
        sort(a,a+s.size()-1);
        for(int i=s.size()-1;i>=s.size()-n;i--)cout<<a[i];
    }
}
int main(){
    solve();
    return 0;
}
