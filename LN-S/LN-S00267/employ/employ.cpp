#include<bits/stdc++.h>
using namespace std;
int n,c[505];string s;long long cnt,ans=1,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]>0){
            cnt++;
        }
    }
    if(cnt<m){
        cout<<0;return 0;
    }
    while(m--){
        ans*=m+1;ans%=998244353;
    }
    cout<<ans;

    return 0;
}
