#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5007];
int C(int nn,int aa){
    int ret=1;
    for(int i=nn;i>nn-aa;i--){
        ret*=i;
        ret%=mod;
    }
    for(int i=1;i<=aa;i++) ret/=i;
    return ret;
}
void subtask1(){
    int ans=0;
    for(int i=7;i<(1<<n);i++){
        vector<int>zt,choose;
        int tmp=i;
        while(tmp){
            zt.push_back(tmp%2);
            tmp/=2;
        }
        while(1){
            if(zt.size()==n) break;
            zt.push_back(0);
        }
        reverse(zt.begin(),zt.end());
        /*for(int j=0;j<n;j++) cout<<zt[j]<<' ';
        cout<<'\n';*/
        for(int j=0;j<n;j++) if(zt[j]) choose.push_back(a[j]);
        if(choose.size()<3) continue;
        int mx=-114514,cnt=0;
        for(int j=0;j<choose.size();j++){
            cnt+=choose[j];
            if(choose[j]>mx){
                mx=max(mx,choose[j]);
            }
        }
        if(cnt>mx*2) ans++;
        ans%=mod;
    }
    cout<<ans<<'\n';
}
void subtask2(){
    int ans=0;
    for(int i=3;i<=n;i++){
        ans+=C(n,i);
        ans%=mod;
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<=30) subtask1();
    else subtask2();
    return 0;
}
