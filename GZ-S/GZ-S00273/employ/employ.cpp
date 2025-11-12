//GZ-S00273
//¹óÑôÒ»ÖÐ Ñî¾ûº­
#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int n,m,c[N],d[N],ans;
string s;
bool vis[20];
void dfs(int x){
	if(x==n+1){	
		int ns=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0' || ns>=c[d[i]])
				ns++;
		if(n-ns>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			d[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

