#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const ll P=998244353;
int n,a[5001];
ll f[5001],C[5001][5001],ans,s;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	f[0]=C[0][0]=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
		for(int j=5000;j>=a[i];--j)(f[j]+=f[j-a[i]])%=P;
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;++i)(ans+=C[n][i])%=P;
	for(int i=1;i<=n;++i)(f[a[i]]+=P-1)%=P;
	for(int i=1,j=1;i<=n;++i){
		for(;j<=a[i];++j)(s+=f[j])%=P;
		(ans+=P-s)%=P;
	}cout<<ans;
}
/*
Now it's 9:11,I passed all the samples of all the tasks.
(The tasks is much easier than last year...)
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
sto Zyj6 orz
I want to play Hollow Knight!
It is 10:12 now,I surf 10825 metres now!
So boring...
*/