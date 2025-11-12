#include<iostream>
using namespace std;
const int N=505;
int n,m,ans,c[N];
bool vis[N];
string s;
void dfs(int x,int cc){
	if(x>n){
		ans+=(n-cc>=m);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(c[i]<=cc||s[x-1]=='0')dfs(x+1,cc+1);
			else dfs(x+1,cc);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
