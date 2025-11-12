#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,flag,f[510][510],s[510],c[510];
ll vis[510],ans;
void dfs(int cur,int v){
	if(cur>n&&v>=m){
		ans++;
		ans%=mod;
		return;
	}
	if(cur>n) return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=cur;
			if(c[i]>=cur-v&&s[cur]==1)dfs(cur+1,v+1);
			else dfs(cur+1,v);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	flag=n;
	string t;
	cin>>t;
	for(int i=1;i<=n;i++){
		s[i]=t[i-1]-'0';
		//cout<<s[i]<<" ";
		flag+=s[i];
	}
	//cout<<flag<<" "<<endl;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(flag<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	//cout<<"111";
	/*f[0][0]=1;
	for(ll i=1;i<=n;i++){
		f[i][0]=f[i-1][0]*(n-i+1)%mod;
		cout<<f[i][0]<<" ";
		for(ll j=1;j<=min(i,m);j++){
			f[i][j]=f[i-1][j]*(n-i+1)%mod;
			if(s[i]==1){
				ll k;
				for(k=n;k>=1;k--){
					if(c[i]<i-j+1) break;
				}
				f[i][j]=(f[i][j]+f[i-1][j-1]*min(n-k,n-i+1)%mod)%mod;
			}
			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<f[n][m];*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
