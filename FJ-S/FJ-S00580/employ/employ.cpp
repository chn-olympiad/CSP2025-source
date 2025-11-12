#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans,cnt;
string s;
int b[505],c[505],a[505];
bool flag=1;
void dfs(int k){
	if(k>n){
		int cnt=0,giveup=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||giveup>=a[c[i]]){
				giveup++;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=m) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			c[k]=i;
			dfs(k+1);
			b[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	if(n-cnt<m){
		cout<<0<<endl;
		return 0;
	}
//	for(int i=0;i<n;i++){
//		if(s[i]=='0'){
//			flag=0;
//			break;
//		}
//	}
//	if(flag){
//		sort(a+1,a+1+n);
//		int giveup=0;
//		for(int i=1;i<=n;i++){
//			if(giveup>=a[i])
//		}
//	}
	if(n<=10){
		dfs(1);
		cout<<ans%mod<<endl;
		return 0;	
	}
	cout<<0<<endl;
	return 0;
}
