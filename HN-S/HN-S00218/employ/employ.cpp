#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=998244353;
int n,m;
string s;
int a[N];
int c[N];
int num[N];
bool vis[N];
long long ans;
void dfs(int now){
	if(now>n){
		int p=0;
		int less=0;
		for(int i=1;i<=n;i++){
		//	cout<<num[i]<<' ';
			if(a[num[i]]>less&&s[i]=='1')p++;
			else less++;
		}
	//	cout<<'\n';
		ans+=(p>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			num[now]=i;
			dfs(now+1);
			//num[now]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		int p;
		cin>>a[i];
	}
	int f=0;
	for(int i=1;i<=n;i++)f+=(s[i]-'0');
	if(f<m){
		cout<<0;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<'\n';
	}else if(f==n){
		int p=0;
		for(int i=1;i<=n;i++)if(a[i]!=0)p++;
		if(p<m)cout<<"0";
		else {
			long long ans=1;
			for(int i=n;i>=1;i--){
				ans*=i;
				ans%=M;
			}
			cout<<ans;
		}
	}
	
	return 0;
}

