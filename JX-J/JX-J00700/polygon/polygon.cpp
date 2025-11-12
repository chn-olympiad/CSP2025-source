#include <bits/stdc++.h>
using namespace std;
int n,a[5003],f[5003],ans;
bool check(int a[],int l){
	int sum=0,maxn=0;
	for(int i=1;i<=l;i++) sum+=a[i],maxn=max(a[i],maxn);
	return sum>(maxn<<1);
}
void dfs(int a[],int it,int step,int gl){
	if(step==gl){
		ans+=check(a,gl),ans%=998244353;
		return;
	}
	for(int i=it+1;i<=n-(gl-step-1);i++){
		a[step+1]=::a[i];
		dfs(a,i,step+1,gl);
		a[step+1]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		memset(f,0,sizeof f);
		dfs(f,0,0,i);
	}
	cout<<ans%998244353<<'\n';
	return 0;
}
