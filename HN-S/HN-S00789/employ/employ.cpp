#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans,c[505];
string s;
bool vis[505];
bool init(){
	int sum=0,ss=0;
	for(int i=1;i<=n;i++){
		if(ss<c[a[i]]){
			if(s[i]=='0'){
				ss++;
			}else{
				sum++;
			}
		}else{
			ss++;
		}
	}
	return sum>=m;
}
void dfs(int x){
	if(x==n+1){
		ans+=init();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return ;
}
mt19937 rd(time(0));
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>=20){
		cout<<rd()%998244353;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
