#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,z=0;
    string s;
    cin>>n>>m;
    cin>>s;
    set<int>a;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
