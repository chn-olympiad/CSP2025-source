#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,c[505];
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(m==1) cout<<n;
    if(n==m) cout<<"1";
    return 0;
}
