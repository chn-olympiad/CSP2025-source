#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    int ans=0,tmp[n],c[n],cnt2=0,fidx=0;
    for(int i=0;i<n;++i){
        cin>>c[i];
        if(s[i]=='1'){
            cnt2++;
            fidx=i;
        }
        tmp[i]=i;
    }
    if(cnt2<m){
        cout<<0;
        return 0;
    }
    do{
        int cnt=0,cnt1=0;
        for(int i=0;i<=fidx;++i){
            if(cnt1<c[tmp[i]]){
                if(s[i]=='1') cnt++;
                else cnt1++;
            }
            else{
                cnt1++;
            }
            if(cnt>=m){
                ans++;
                break;
            }
            
        }
        if(ans>mod) ans-=mod;
    }while(next_permutation(tmp,tmp+n));
    cout<<ans%mod;
    return 0;
}