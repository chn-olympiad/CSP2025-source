#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,a;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='9'||s[i]=='8'||s[i]=='7'||s[i]=='6'||s[i]=='5'||s[i]=='4'||s[i]=='3'||s[i]=='2'||s[i]=='1'||s[i]=='0'){
            a+=s[i];
        }
    }
    sort(a.begin(),a.end());
    for(long long i=a.length()-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
