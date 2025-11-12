#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans;
string s;
int n,m,c[505],cnt;
long long F(int x,int y){
    long long tot=1;
    for(int i=x;i>=y;i--){
        tot=tot*i%MOD;
    }
    return tot%MOD;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+1+n,greater<int>());
    for(int i=1;i<=n;i++){
        if(c[i]==0){
            break;
        }
        cnt++;
    }
    if(cnt<m){
        cout<<0;
        return 0;
    }
    for(int i=m;i<=cnt;i++){
        ans+=F(cnt,cnt-m+1);
    }
    cout<<ans;
    return 0;
}
