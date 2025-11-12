#include<bits/stdc++.h>
using namespace std;
long long n,s[5005],ans=0,shu=0,maxn,cnt=0;
void f(int x){
    cnt+=s[x];
    shu++;
    if(x==1){
        if(shu>=3 and cnt>maxn*2)ans++;
        cnt-=s[x];
        shu--;
        return;
    }
    else if(shu>=3 and cnt>maxn*2)ans++;
    for(int i=x-1;i>=1;--i)f(i);
    cnt-=s[x];
    shu--;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    sort(s+1,s+1+n);
    if(n>20 and s[n]==1){
        for(int i=n-1;i>=3;i--){
            ans+=pow(i-2,2);
        }
        ans++;
        ans%=998244353;
        cout<<ans;
        return 0;
    }
    for(int i=3;i<=n;++i){
        maxn=s[i];
        f(i);
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
