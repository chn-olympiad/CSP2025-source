#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int a[5010];
long long n,ans,jc[5010];
bool flag;
long long ksm(long long a,long long b){
	long long num=1;
	while(b){
		if(b&1){
			num*=a;
			num%=M;
		}
		a*=a;
		a%=M;
		b>>=1;
	}
	return num;
}
void dfs(int x,int dis,int sum,int mx){
	if(x>n){
		if(dis<3)return;
		if(sum-mx>mx)ans++;
		return;
	}
	dfs(x+1,dis+1,sum+a[x],a[x]);
	dfs(x+1,dis,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=1;
	}
	sort(a+1,a+n+1);
	if(flag)dfs(1,0,0,0);
	else {
		jc[0]=1;
		for(long long i=1;i<=n;i++){
			jc[i]=jc[i-1]*i;
			jc[i]%=M;
		}
		for(long long i=3;i<=n;i++){
			ans+=jc[n]*ksm(jc[i],M-2)%M*ksm(jc[n-i],M-2)%M;
			ans%=M;
		}
	}
	cout<<ans;
	return 0;
} 
