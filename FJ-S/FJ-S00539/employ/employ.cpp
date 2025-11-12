#include<bits/stdc++.h>
using namespace std;
int c[20],n,m,ans,l,w;
int p[20];
bool vis[20];
string s;
void dfs(int n,int step) {
	if(step>n) {
		int l=0,w=0;
		for(int i=1;i<=n;i++) {
			//cout<<p[i]<<" ";
			if(s[i-1]=='0'||l>=c[p[i]]) {
				l++;
			}
			else if(s[i-1]=='1'){
				w++;
			}
		}
		//cout<<"\n"<<l<<" "<<w<<"\n"; 
		if(w>=m) {
			++ans;
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			p[step]=i;
			vis[i]=1;
			dfs(n,step+1);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	dfs(n,1);
	cout<<ans;
	return 0;
}
