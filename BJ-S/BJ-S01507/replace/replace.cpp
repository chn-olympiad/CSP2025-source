#include<bits/stdc++.h>
using namespace std;
string a[100005],b[100005];
int dif[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int len=a[i].size();
		for(int j=0;j<len;j++)if(a[i][j]!=b[i][j])dif[i]++;
	}
	for(int t=1;t<=m;t++){
		int diff=0;
		string x,y;
		cin>>x>>y;
		int len=x.size();
		int ans=0;
		for(int i=0;i<len;i++){
			if(x[i]!=y[i])diff++;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<len;j++){
				string g=x.substr(j,a[i].size());
				string q=y.substr(j,a[i].size());
				if(g==a[i]&&q==b[i]&&diff==dif[i])ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
