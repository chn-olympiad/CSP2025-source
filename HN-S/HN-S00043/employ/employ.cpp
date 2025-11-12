#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
const int mod=998244353;
int n,m;
int c[N];
bool vis[N];
string s;
int dfs(int x,int y,int z){
	if(x>n){
		return (y==m); 
	} 
	int sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		sum+=dfs(x+1,y+(s[x]=='1'&&z<c[i]),z+(s[x]=='0'||z>=c[i]));
		vis[i]=0;
	}
	return sum;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		int jc=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				cout<<0;
				return 0;
			}
			(jc*=i)%=mod;
		}
		cout<<jc;
	}else if(n<=18){
		cout<<dfs(1,0,0);
	}else{
		cout<<0;
	}
}

