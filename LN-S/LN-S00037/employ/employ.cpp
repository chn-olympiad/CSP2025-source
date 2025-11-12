#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define qrw ios::sync_with_stdio(0),cin.tie(0)
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    qrw;
    int n,m;
    if(n>30){
        cout<<0<<endl;
        return 0;
    }
    string s;
    int c[10005];
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    vector<int> p;
    for(int i=1;i<=n;i++) p.push_back(i);
    int ans=0;
    do{
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt>=c[p[i]]||s[i]=='0') cnt++;
        }
        if(n-cnt>=m) ans++;
    }while(next_permutation(begin(p),end(p)));
    cout<<ans<<endl;
}