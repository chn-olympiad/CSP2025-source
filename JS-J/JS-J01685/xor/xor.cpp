#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    if(k==0){
        int ans{};
        stack<int>stk;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x==1&&stk.top()==1){
                stk.pop();
                stk.push(0);
            }
        }
        while(!stk.empty()){
            int x=stk.top();
            stk.pop();
            if(x==0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    if(k==1){
        int ans{};
        stack<int>stk;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x==0&&stk.top()==0){
                stk.pop();
                stk.push(1);
            }
        }
        while(!stk.empty()){
            int x=stk.top();
            stk.pop();
            if(x==1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}