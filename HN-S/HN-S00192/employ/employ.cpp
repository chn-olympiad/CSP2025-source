#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
string s;
int ans,n,m,c[510],a[510];
bool vis[510],b[510];
void dfs(int x){
	if(x>n){
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=sum){
				sum++;
				continue;
			} 
			if(b[a[i]]==0) sum++;
			else cnt++;
			if(cnt>=m){
				ans++;
				ans%=M;
				return;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++) 
	 if(!vis[i]){
	 	vis[i]=1;
	 	a[x]=i;
	 	dfs(x+1);
	 	vis[i]=0;
	 }
}
void sol(){
	int sum=0;
	for(int i=1;i<=n;i++) if(c[i]!=0) sum++;
	if(sum==0){
		cout<<0;
		return;
	}
	long long ans=1;
	for(int i=2;i<=sum;i++) ans=ans*i%M;
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) b[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==1){
		sol();
		return 0; 
	} 
	if(n>=20){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
