#include<bits/stdc++.h>
using namespace std;
int n,m,s,c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]==0) cnt++;
    }
    if(n-cnt<m) cout<<0;
    else{
        long long ans=1;
        for(int i=2;i<=n;i++) ans*=i;
        cout<<ans%998244353;
    }
    return 0;
}
