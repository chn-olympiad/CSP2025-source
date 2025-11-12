#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
int vi[15],c[15],p[15];
int n,m;
string s;
long long ans=0;
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i-cnt-1>=c[p[i]]){
				continue;
			}
			if(s[i-1]=='1'){
				cnt++;
			}
		}
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vi[i]){
			continue;
		}
		p[x]=i;
		vi[i]=1;
		dfs(x+1);
		vi[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<'\n';
}
