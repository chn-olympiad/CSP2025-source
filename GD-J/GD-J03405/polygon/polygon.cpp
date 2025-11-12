#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
map<long long,int> e,f,g;
bool b[5005];
void dfs(int x,int s,int d){
	if(d*2<s)
	{
		if(!e[x*5000+d]||!f[s*5000+x]||!g[s*5000+d])
		{
			e[x*5000+d]=f[s*5000+x]=g[s*5000+d]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			dfs((x*i)%5000,s+a[i],max(d,a[i]));
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
