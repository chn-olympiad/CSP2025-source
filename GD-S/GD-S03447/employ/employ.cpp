#include<bits/stdc++.h>
using namespace std;
int n,tot,ans,m,c[510],s[510],c_[510];
bool v[510];
void dfs(int i)
{
	if(i>n){
		ans+=(tot>=m);
		return;
	}
	for(int j=1;j<=n;j++){
		if(v[j])
			continue;
		v[j]=true;
		tot+=(i-tot-1<c[j]&&c_[i]);
		dfs(i+1);
		tot-=(i-tot-1<c[j]&&c_[i]);
		v[j]=false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>cc;
		c_[i]=(cc=='1');
		s[i]=s[i-1]+(cc=='0');
	}
	for(int i=n;i>=1;i--)
		s[i]=s[i-1];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
}
