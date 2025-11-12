#include <bits/stdc++.h>
using namespace std;
int n,m,a;
int ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a>=s[i]) ans++;
    }if(ans>=m){
        ans=m;
        cout<<ans;
    }else cout <<ans+1<<endl;
    return 0;
}
