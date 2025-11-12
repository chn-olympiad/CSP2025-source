#include<iostream>
#include<algorithm>
using namespace std;
long long mod=998244353,ans,a[5005],n;
bool v[5005];
void dfs(int x,int y,int k){
	v[y]=1;
	if(k>=x){
		long long sum=0,maxx=0;
		for(int i=1;i<=n;i++)
			if(v[i]==1)
				sum+=a[i],maxx=max(maxx,a[i]);
		if(sum>maxx*2)
			ans++;
		ans%=mod;
		return;
	}
	for(int i=y+1;i<=n;i++)
		if(!v[i])
			dfs(x,i,k+1),v[i]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,0,0);
		for(int j=0;j<=n;j++)
			v[j]=0;
	}
	cout<<ans;
} 
