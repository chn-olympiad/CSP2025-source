#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const ll N=600,M=998244353;
ll n,m,ans,c[N];
char a[N];
ll num_0,num_1,cnt=0,cnt0[N],cnt1[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
		cnt0[i]=cnt0[i-1];
		cnt1[i]=cnt1[i-1];
		if (a[i]=='0') cnt0[i]++;
		if (a[i]=='1') cnt1[i]++;
	}
	for (ll i=1;i<=n;i++){
		cin>>c[i];
	}
//	sort(c+1,c+1+n,cmp);
	if (m==n){
		cout<<0<<' ';
		return 0;
	}
	if (m==1){
		long long op=0;
		for (op=1;op<=n;op++)
			if (cnt1[op]==1) break;
		op--;
		for (ll i=1;i<=n;i++){
			if (i!=n) ans=ans*i%M;
			if (c[i]>op) cnt++; 
		}
	}
	cout<<(cnt*ans)%M;
	return 0;
}
