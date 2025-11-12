#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int ans=0;
    getline(cin,s);
    int lineh=s.size();
    string a[lineh];
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            ans++;
            a[ans]=s[i];
        }
    }
    sort(a+1,a+1+ans);
    for(int i=ans;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}

