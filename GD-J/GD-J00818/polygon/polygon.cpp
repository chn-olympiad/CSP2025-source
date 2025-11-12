#include<bits/stdc++.h>
using namespace std;

const int P=998244353;
long long n,a[5010],ans[5010],s[5010],sum=0,k;
bool A=1;

void dfs(long long x){
	if(x==1){
		if(sum>a[k]) ans[k]++;
		ans[k]%=P;
		sum+=a[x];
		if(sum>a[k]) ans[k]++;
		ans[k]%=P;
		sum-=a[x];
		return;
	}
	sum+=a[x];
	dfs(x-1);
	sum-=a[x];
	dfs(x-1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) A=0; 
	}
	sort(a+1,a+1+n);
	
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(A){
		cout<<n-2;
		return 0;
	}

	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(k=3;k<=n;k++){
		sum=0;
		ans[k]=ans[k-1];
		ans[k]%=P;
		if(s[k-1]<a[k]) continue;
		dfs(k-1); 
	}
	cout<<ans[n];
	return 0;
}
