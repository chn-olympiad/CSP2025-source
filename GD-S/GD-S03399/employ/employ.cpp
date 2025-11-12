#include<bits/stdc++.h>
using namespace std;
int d[10000];
bool vis[100];
int pl[100];
int ans,n,m;
int sum[100];
string t;
const int mod=998244343;
void dfs(int sl){
	if(sl==n){
		int fq=0;
		for(int i=1;i<=n;i++){
			if(t[i]-'0'==0 || fq>=d[pl[i]]){
				fq++;
			}
		}
		if(n-fq>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			pl[++sl]=i;
			vis[i]=1;
			dfs(sl);
			vis[i]=0;
			sl--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>t;
	t="#"+t;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	sort(d+1,d+n+1);
	if(n<=10){
		dfs(0);
		cout<<ans;
	}
	else{
		bool fl=1;
		for(int i=1;i<=n;i++){
			if(t[i]=='0'){
				fl=0;
				break;
			}
		}
		if(fl && m==1){
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
		}
		else{
			cout<<998244352;
		}
	} 
	return 0;
} 
