#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505],d[505];
string s;
signed main(){
   freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=i;
    }
    int ans=0;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt>=a[d[i]]){ cnt++;
                continue;
            }
            if(s[i]=='0') cnt++;
        }
        if(n-cnt>=m) ans++;
    }while(next_permutation(d+1,d+1+n));
    cout<<ans;
    return 0;
}
