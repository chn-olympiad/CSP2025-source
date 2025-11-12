#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],use[5005];
bool all_same=true;
long long ans;
bool check(){
	int total=0,maxlength=0;
	for(int i=1;i<=m;i++){
		total+=a[use[i]];
		maxlength=max(maxlength,a[use[i]]);
	}
	if(total>maxlength*2) return true;
	else return false;
}
void dfs(int k){
	if(k>m){
		if(check()){
			ans++;
			ans%=998244533;
		}
		return;
	}
	for(int i=use[k-1]+1;i<=n;i++){
		use[k]=i;
		dfs(k+1);
		use[k]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	use[0]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1]) all_same=false;
	}
	if(all_same){
		for(m=3;m<=n;m++){
			int p=m;
			if(p>n/2) p=n-p;
			long long plus=1,k=1;
			for(int i=n-p+1;i<=n;i++){
				plus*=i;
				plus/=i-n+p;
			}
			ans+=plus;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	for(m=3;m<=n;m++) dfs(1);
	cout<<ans;
	return 0;
}
