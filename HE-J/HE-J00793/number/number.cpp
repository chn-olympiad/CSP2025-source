#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int ma=0,a[s.size()+5],t=0;
    for(int i=0;i<s.size();i++)
        if(s[i]<='9'&&s[i]>='0'){
            t++;
            a[t]=s[i]-'0';
        }
    bool q=0;
    sort(a+1,a+1+t);
    for(int i=t;i>=1;i--){
        if(a[i]!=0||i==1)q=1;
        if(q==1)cout<<a[i];
    }
    return 0;
}
