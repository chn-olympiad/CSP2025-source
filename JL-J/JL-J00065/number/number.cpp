#include<bits/stdc++.h>
using namespace std;
int n,a[1000010];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            n++;
            a[n]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    if(a[1]==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
