#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,res,m,pos;
int a[5005],v[5005];
bool b[5005];
void dfs(int step){
	if(step==m+1){
		int sum=0,maxn=0;
		for(int i=1;i<=m;i++){
			sum+=v[i];
			if(v[i]>maxn){
				maxn=v[i];
			}
		}
		if(sum>maxn*2){
			res++;
			res%=998244353;
		}
		memset(v,0,sizeof(v));
		pos=0;
		return ;
	}	
	for(int i=1;i<=step;i++){
		if(b[i]==0){
			b[i]=1;
			v[++pos]=a[i];
			dfs(step+1);
			b[i]=0;
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int e=0,mx=0;
		for(int i=1;i<=n;i++){
			e+=a[i];
			if(a[i]>mx){
				mx=a[i];
			}
		}
		if(e>mx*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		m=i;
		dfs(1);
		ans+=res;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
