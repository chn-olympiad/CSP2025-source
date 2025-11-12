#include <bits/stdc++.h>
using namespace std;
int x[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int n=0;
    cin>>s;
    for (int i=0;i<=s.size();i++){
        if (s[i]>='1' and s[i]<='9'){
            x[n]=s[i]-'0';
            n++;
        }
    }
    sort(x,x+n);
    for (int i=n-1;i>=0;i--){
        cout<<x[i];
    }
    return 0;
}
