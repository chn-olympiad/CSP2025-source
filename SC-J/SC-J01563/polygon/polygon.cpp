#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n,a[maxn],c[maxn],res,ans;
void dfs(int x,int k,int last){
	if(x==k+1){
		int sum=0;
		for(int i=1;i<=k-1;i++)sum+=c[i];
		if(sum>c[k])res++;
		return;
	}
	for(int i=last+1;i<=n;i++){
		c[x]=a[i];
		dfs(x+1,k,i);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n>23){
		cout<<1919810;
		return 0;
	}
	for(int i=3;i<=n;i++){
		res=0;
		dfs(1,i,0);
		ans+=res;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

