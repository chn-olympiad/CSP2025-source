#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int find(int m,int n){
    int s=1;
    int p=0;
    for(int i=n;;i--){
        if(p==m) break;
        s*=i;
        p++;
    }
    for(int i=1;i<=m;i++){
        s/=i;
    }
    return s;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
    }
    for(int i=m;i<=n;i++){
        ans+=find(i,n);
      //  cout<<find(i,n)<<endl;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
