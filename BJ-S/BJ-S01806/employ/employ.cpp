#include <bits/stdc++.h>
using namespace std;
string s;int total[505];
int c[505];
int n,m;
long long ans=0;
void dfs(int now,bool k[],int emp) {
	if (now==n+1) {
		if (emp>=m) ans++;
		//cout<<emp<<' ';
		return ;
	}
	for (int i=1;i<=n;i++) {
		if (c[i]<total[now]&&!k[i]) {
			k[i]=1;
			dfs(now+1,k,emp+1);
			//cout<<i<<' ';
			k[i]=0;
		}
		else if (!k[i]&&total[now]==-1){
			k[i]=1;
			dfs(now+1,k,emp);
			k[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//int n,m;
	cin>>n>>m;
	cin>>s;
	int f=n;
	for (int i=0;i<n;i++) {
		if (s[i]=='1') {
			total[i+1]=f;
		}
		else {
			total[i+1]=-1;
			f--;
		}
		
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	bool k[505]={};
	dfs(1,k,0);
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}