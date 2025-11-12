#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005],t;
bool cmp(int a,int b){
    return (a>=b);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9') ans[++t]=s[i]-'0';
    sort(ans+1,ans+t+1,cmp);
    for(int i=1;i<=t;i++) cout<<ans[i];
    return 0;
}