#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=5010,jc[21]={0,0,0,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,237554682,331032489,972509923};
int n,a[N],ans[N];
bool vis[N];
int C(int n,int m){
	int nn=n,mm=m,res1=1,res2=1;
	while(mm--){
		res1*=nn;
		res1%=mod;
		nn--;
	}
	mm=m;
	while(m--){
		res2*=mm;
		mm--;
	}
	return res1/res2%mod;
}
void dfs(int k,int summ,int maxx,int now){
	if(now==k){
		if(summ>2*maxx){
			ans[k]++;
			ans[k]%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k,summ+a[i],max(maxx,a[i]),now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n<3){
		for(int i=1,abc;i<=n;i++)
			cin>>abc;
		printf("0");
		return 0;
	}
	if(n==3){
		int su=0,ma=-1;
		for(int i=1,xx;i<=n;i++){
			scanf("%lld",&xx);
			su+=xx;
			ma=max(ma,xx);
		}
		if(su>2*ma)
			printf("1");
		else
			printf("0");
		return 0;
	}
	int shu1=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1)
			shu1++;
	}
	if(shu1==n){
		int anss=0;
		for(int i=3;i<=n;i++){
			anss+=C(n,i);
			anss%=mod;
		}
		printf("%lld",anss);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int k=3;k<=n;k++){
		dfs(k,0,0,0);
		ans[k]=ans[k]/jc[k];
		ans[k]%=mod;
	}
	int vvv=0;
	for(int i=3;i<=n;i++)
		vvv+=ans[i];
	printf("%lld",vvv);
	return 0;
}