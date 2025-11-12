#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
int n,a[5050],s[5050];
ll cnt;
ll kck(ll rm,ll mxn,ll t){
    if(t==0){
        if(rm>0){
            return 1;
        }
        return 0;
    }
    ll tc=0;
    for(int i=1;a[i]<=rm,i<mxn;i++)
        tc=(tc+kck(rm-a[i],i,t-1)%MOD)%MOD;
    return tc;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
    for(int r=3;r<=n;r++){
        for(int kc=1;r-kc>=3;kc++){
            cnt=(cnt+(kck(s[r-1]-a[r],r,kc)%MOD))%MOD;
        }
    }
    cout<<cnt;
	return 0;
}
