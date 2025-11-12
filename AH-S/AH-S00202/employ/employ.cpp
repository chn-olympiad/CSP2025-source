#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000],p,ans;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(s.begin(),s.end());
    do{
        p=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(p>=a[i]||s[i-1]=='0'){
                p++;
                continue;
            }else{
                cnt++;
            }
        }
        if(cnt>=m) ans++;
        //ans%=998244353;
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans;
    return 0;
}
