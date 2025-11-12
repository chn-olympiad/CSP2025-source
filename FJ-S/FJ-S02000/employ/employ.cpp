#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[550];
int c[550];
int st[550];

int sum;
void dfs(int x,int sh){
	if(x==n+1){
		if(n-sh>=m){
			sum++;
			sum%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			if(sh>=c[i]){
				dfs(x+1,sh+1);
			}
			else if(a[x]==0){
				dfs(x+1,sh+1);
			}
			else if(a[x]==1){
				dfs(x+1,sh);
			}
			st[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int o1=0,o0=0;
	for(int i=0;s[i];i++){
		a[i+1]=s[i]-'0';
		if(a[i+1]==0) o0++;
		else o1++;
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	int o=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			o++;
		}
	}
	if(o==n){
		cout<<0;
	}
	else if(o1==n&&o==0){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans%mod*i%mod;
			ans%=mod;
		}
		cout<<ans;
	}
	else if(o0==n){
		cout<<0;
	}
	else{
		dfs(1,0);
		cout<<sum;
	}
	
	return 0;
}
