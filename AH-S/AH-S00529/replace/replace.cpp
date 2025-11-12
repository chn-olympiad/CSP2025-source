#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,ans=0,q;
    cin>>n>>q;
    string a[2*n+1];
    for(int i=0;i<2*n;i++)cin>>a[i];
    for(int j=0;j<q;j++){
        string s1,s2;
        cin>>s1>>s2;
        if(s1==s2)ans++;


       cout<<ans<<endl;
    }

return 0;}
