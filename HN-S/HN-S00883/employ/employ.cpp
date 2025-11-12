#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,p[N],c[N],ans;
bool f[N],fa=1;
string s;
void dfs(int x){
	if(x==n){
		int q=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(q>=c[p[i]]||s[i-1]=='0') q++;
			else cnt++;
		}
		if(cnt>=m) ans++;
		return;
	}
	x++;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			p[x]=i;
			f[i]=1;
			dfs(x);
			f[i]=0; 
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			fa=0;
			break;
		}
	}
	if(fa){
		long long ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0);
	cout<<ans;
	return 0;
} 
