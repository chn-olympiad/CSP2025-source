#include<bits/stdc++.h>
using namespace std;
string s,a[10];
long long n;
 int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]<='9'&&s[i]>='0')a[s[i]-'0']+=s[i];
    }
    for(int i=9;i>=0;i--){
        if(!a[i].empty())cout<<a[i];
    }
    return 0;
}