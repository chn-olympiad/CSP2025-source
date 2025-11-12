#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,a[5005],fl[5005],tot,ps,mx,ans;
int qpow(int a,int b){
	int tot=1;
	while(b){
		if(b%2) tot*=a,tot%=mod;
		b=b/2;
		a*=a,a%=mod;
	}
	return tot;
}
void main1(){
	for(int i=1;i<(1<<n);i++){
		ps=tot=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))) ps=j,tot+=a[j];
		}
		if(tot>2*a[ps]) ans++;
	}
	cout<<ans%mod<<endl;
}
void main3(){
	cout<<(qpow(2,n)+mod-n*(n-1)/2+mod-n+mod-1)%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//input here
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	if(n<=20) main1();
	else if(mx==1) main3();
}
/*
 * Ended.
 * Will it be 364 pts?
 * Last year in OI, better road is waiting for me.
 */
