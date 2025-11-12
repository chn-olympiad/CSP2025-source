#include<bits/stdc++.h>
using namespace std;

int n,m,a[505],c[505],ans,k[505];
char p[505];
bool l[505];
void dfs(int s){
	if(s>n){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			if(i-k[i-1]-1<=a[c[i]])
				k[i]=k[i-1]+(p[c[i]]-'0');
		}
		if(k[n]>=m) ans++;
	}else{
		for(int i=1;i<=n;i++){
			if(l[i]==0){
				l[i]=1;
				c[s]=i;
				dfs(s+1);
				l[i]=0;
			}
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
