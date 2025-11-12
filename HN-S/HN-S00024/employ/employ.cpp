#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int p=998244353;
int n,m;
string s;
int c[N],q[N],b[N];
int ans=0;
void dfs(int u){
	if(u==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			if(cnt>=c[q[i]]){
				cnt++;
				continue;
			}
		}
		if(n-cnt>=m)ans++; 
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			q[u]=i;
			dfs(u+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
