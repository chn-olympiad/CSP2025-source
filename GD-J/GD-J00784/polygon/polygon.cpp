#include<bits/stdc++.h>
using namespace std;
void fuck(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	return;
}
const long long mod=998244353;
long long a[1145140],n,i,ans,k,jb,len,sb;
bool cmp(int x,int y){
	return x>y;
}
void dfs(long long i){
	if(i==n+1){
		if(k>jb&&len>=3)ans++;
		ans=ans%mod;
		return;
	}
	dfs(i+1);
	k+=jb;
	long long jbb=jb;
	jb=a[i];
	len++;
	dfs(i+1);
	len--;
	jb=jbb;
	k-=jb;
	return;
}
int main(){
	fuck();
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)sb++;
	}
	if(sb==n){
		ans=1;
		for(i=1;i<=n;i++){
			ans=ans*2%mod;
		}
		cout<<ans-n-n*(n-1)/2-1;
		return 0;
	}
	ans=0;
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans;
	return 0;
}
