#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5010];
long long sum=0;
long long d[5010],o;
long long P=998244353;
void dfs(long long num,int s,int e,int xx){
	if(num>o&&xx>=2){
		int v=e-s+1;
		for(int i=1;i<=v;i++){
			sum=(sum+(d[v]/(d[v-i]*d[i]))%P)%P;
		}
		sum++;
		return ;
	}
	if(s==e+1)return ;
	dfs(num+a[s],s+1,e,xx+1);
	dfs(num,s+1,e,xx);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			k++;
		}
	}
	sort(a+1,a+n+1);
	d[0]=1;
	for(int i=1;i<=n;i++){
		d[i]=(d[i-1]*i);
	}
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(k==n){
		for(int i=3;i<=n;i++){
			sum=(sum+(d[n]/((d[n-i]*d[i])))%P)%P;
		}
		cout<<sum;
		return 0;
	}
	for(int i=2;i<=n;i++){
		o=a[i];
		dfs(0,1,i-1,0);
	}
	cout<<sum%P;
	return 0;
}
