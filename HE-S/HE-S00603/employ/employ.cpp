#include <bits/stdc++.h>
using namespace std;
const int N=505;
int p[N],n,m,c[N],ans,vis[N];
int z[N];
char a;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!z[i] || cnt>=c[p[i]]) cnt++;
		if(cnt>n-m) return false;
	}
	return true;
}
void dfs(int x){
	if(x>n){
		if(check()) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		z[i]=a-'0';
	}
//	cout<<"re\n";
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
