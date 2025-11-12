#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=(1<<21);
int a[500005],sum[500005],f[500005],n,k,t[N];
void solve(){
	for (int i=1;i<=n;++i){
//		bool flag=0;
		if (a[i]==k){
			f[i]=f[i-1]+1;
			continue;
		}	
//		for (int j=i-1;j>=1;--j){
//			if (flag)f[i]=max(f[i],f[j]+1);
//			if (sum[i]^sum[j-1]==k)flag=1;
//			f[i]=max(f[i],f[j]);
//		}
		for (int j=i-1;j>=1;--j){
			if ((sum[i]^sum[j-1])==k){
				f[i]=max(f[i],f[j-1]+1);
				//cout<<"+:"<<i<<' '<<j<<' '<<" "<<(sum[i]^sum[j-1])<<'\n';
				break;
			}
			f[i]=max(f[i],f[j]);
		}
	}
	cout<<f[n];
//	for (int i=1;i<=n;++i)cout<<f[i]<<" ";
}
void solve2(){
	int maxn=0;
	for (int i=1;i<=n;++i){
		if (a[i]==k){
			f[i]=f[i-1]+1;
			t[sum[i-1]]=max(t[sum[i-1]],f[i-1]);
			continue;
		}
		f[i]=max(t[(sum[i]^k)]+1,maxn);
		t[sum[i]]=max(t[sum[i]],f[i]);
		t[sum[i-1]]=max(t[sum[i-1]],f[i-1]);
		maxn=max(maxn,f[i]);
	}
//	for (int i=1;i<=n;++i)cout<<f[i]<<" ";
	cout<<f[n];
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;++i)cin>>a[i];
	for (int i=1;i<=n;++i)sum[i]=(sum[i-1]^a[i]);
	if (n<=5000)solve();
	else solve2();
}
