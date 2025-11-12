#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

const int N=505,M=998244353; 

int q,n,m,k,cnt=0,cnt2=0;
int c[N];
long long ans=0;
bool a[N],v[N];

void dfs(int k,int g){
	if(k>n){
		if(n-g>=m){
			ans++;ans%=M; 
		}
		return;
	}
	if(n-g<m) return;
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(k+1,g+(!a[k]||(c[i]<=g)));
			v[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		if(c=='1') cnt++,a[i]=1;else a[i]=0;
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	if(cnt==n){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;ans%=M;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
 
