#include<bits/stdc++.h>
using namespace std;
int in(){
	char c=getchar();
	int f=1,k=0;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k*=10;
		k+=c-'0';
		c=getchar();
	}
	return k*f;
}

const int N=5e4+7;
long long ans,mod=998244353;
int n,a[N],b[N];
bool v[N];
void dfs(int maxn,int sum,int id,int num){
	ans%=mod;
	if(sum>2*maxn&&num>=3){
//		cout<<sum<<" "<<maxn<<"\n"; 
		ans++;
	}
	for(int i=id+1;i<=n;i++){
		if(a[i]>maxn){
			if(v[i])continue;
			v[i]=1;
			dfs(a[i],sum+a[i],i,num+1);
		}else{
			if(v[i])continue;
			v[i]=1;
			dfs(maxn,sum+a[i],i,num+1);
		}
//		dfs(maxn,sum,i);
		v[i]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=in();
	for(int i=1;i<=n;i++){
		a[i]=in();
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	cout<<ans%mod;
	return 0;
}
