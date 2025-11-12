#include <bits/stdc++.h>
using namespace std;
int p[5007],n,ans;
const int mod=998244353;
bool v[5007];
void dfs(int s,int a){
	int l=0,maxn=0;
	v[a]=1;
	s--;
	if (s==0){
		for (int i=1;i<=n;i++)
			if (v[i]==1){
				l+=p[i];
				maxn=p[i];
			}
		if (l>2*maxn){
			//for (int i=1;i<=n;i++)
			//	if (v[i]==1)
			//		cout<<p[i]<<' ';
			//cout<<endl;
			ans++;
			ans%mod;
		}
		v[a]=0;
		return ;
	}
	for (int i=a;i<n;i++)
		dfs(s,i+1);
	v[a]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for (int i=3;i<=n;i++)
		for (int j=1;j<=n-i+1;j++)
			dfs(i,j);
	cout<<ans;
	return 0;
}
