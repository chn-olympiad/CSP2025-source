#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],flag[5005],mx;
long long tot,ans;
stack<int>sta;
bool cmp(int x,int y){
    return x>y;
}void srch(int m){
    if(m>n-3)return;
    for(int i=1;i<=n;i++){
        if(flag[b[i]])continue;
        sta.push(b[i]);
        flag[b[i]]=1;
        tot-=b[i];
        mx=b[i];
        if(tot>mx*2){
            ans++;
            ans%=998244353;
        }srch(++m);
        sta.pop();
        flag[b[i]]=0;
        tot+=b[i];
    }
}int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(flag,0,sizeof flag);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        tot+=b[i];
    }sort(b+1,b+n+1,cmp);
    if(tot>b[1]*2)ans=1;
    srch(1);
    cout<<ans;
    return 0;
}
