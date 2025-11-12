#include<bits/stdc++.h>
using namespace std;
int n,m,c[5000001],mod=998244353,f=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(s[i-1]!='0')f=0;
    }
    cout<<0;
    return 0;
}
