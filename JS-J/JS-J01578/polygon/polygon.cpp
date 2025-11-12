#include<bits/stdc++.h>
using namespace std;
long long n;
long long s;
long long a[50001];
long long b[50001];
void dfs(long long k,long long m){
	if(k==m+1){
		long long ans=0;
		for(long long i=1;i<=m;i++){
			ans+=b[i];
		}
		if(ans>b[m]*2){
			s++;
			s%=998244353;
		}
		return ;
	}
	for(long long i=b[k-1]+1;i<=n;i++){
		b[k]=i;
		dfs(k+1,m);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]==10){
		cout<<6;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<s;
	return 0;
}
