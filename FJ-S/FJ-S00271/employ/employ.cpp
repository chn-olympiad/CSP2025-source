#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510];
string s;
int num[1050][18];
bool vis[18];
int tot=0;
void dfs(int k,int a[18]){
	if(k==n){
		tot++;
		for(int j=0;j<n;j++){
			num[tot][j]=a[j];
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			dfs(k+1,a);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++) cin >> c[i];
	bool flag=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			flag=1;
			break;
		}
	}
	if(!flag){
		long long ans=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=0) cnt++;
		}
		if(cnt>=m){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
		}
		cout << ans;
	}
	else if(n<8){
		long long ans=0;
		int a[18];
		dfs(0,a);
		for(int i=1;i<=tot;i++){
			int cnt=0,sum=0;
			for(int j=0;j<n;j++){
				if(s[j]=='0') cnt++;
				else if(c[num[i][j]]>cnt) sum++;
			}
			if(sum>=m) ans=(ans+1)%mod;
		}
		cout << ans;
	}
	else cout << 0;
	return 0;
}
