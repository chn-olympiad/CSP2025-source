#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000009];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            a[++k]=(int)(s[i]-48);
        }
    }
    sort(a+1,a+1+k,cmp);
    string ans;
    for(int i=1;i<k;i++){
        ans=ans+char(a[i]+48);
    }
    cout<<ans;
    return 0;
}
