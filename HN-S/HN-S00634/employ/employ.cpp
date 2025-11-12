#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505;
bool s[N],vis[N]; 
int c[N],cnt=0,n,m;
void dfs(int x,int y,int z){
	if(x>=m){
		cnt++;
	}
	if(z>n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true)continue;
		vis[i]=true;
		if(s[z]==1&&y<c[i]){
			dfs(x+1,y,z+1);
		}else{
			dfs(x,y+1,z+1);
		}
		vis[i]=false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		s[i]=a-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0,1); 
	cout<<cnt<<endl;
	return 0;
}
