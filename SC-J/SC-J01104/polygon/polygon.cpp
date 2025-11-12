#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n;
int a[5145],maa;
int fact[5002],infact[5002],ans;
bool cmp(int a,int b){
	return a>b;
}
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*a)%p;
		a=(a*a)%p;
		b>>=1;
	}return res;
}
void add(){
	fact[0]=infact[0]=1;
	for(int i=1;i<=5000;i++)fact[i]=(fact[i-1]*i)%p;
	int kk=qpow(fact[5000],p-2);
	for(int i=5000;i>=1;i--){infact[i]=kk;kk=(kk*i)%p;}
}
int C(int n,int m){
	return ((fact[n]*infact[n-m])%p*infact[m])%p;
}
int dd[1145];
void dfs(int st,int x,int sum,int idx){
	if(sum>st){
		ans=(ans+qpow(2,n-idx))%p;
		return ;
	}
	for(int i=idx+1;i<=n;i++){
		dd[x+1]=a[i];
		dfs(st,x+1,sum+a[i],i);
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maa=max(maa,a[i]);
	}
	if(maa==1){
		add();
		for(int i=3;i<=n;i++)ans=(ans+C(n,i))%p;
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		dd[1]=a[i];
		dfs(a[i],1,0,i);
	}cout<<ans;
	return 0;
}
