#include<iostream>
#include<string>
#include<cstring>
const int mod=998244353,N=20;
int n,m,sum,c[N],a[N];
unsigned long long ans;
bool vis[N];
std::string s;
void dfs(int now,int a[]){
	if(now==n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&i-sum-1<c[a[i]]){
				sum++;
			}
		}
		if(sum>=m){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=true,a[now+1]=i;
		dfs(now+1,a);
		vis[i]=false,a[now+1]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		std::cin>>c[i];
		if(c[i]==0){
			sum++;
		}
	}
	dfs(0,a);
	std::cout<<ans;
	return 0;
}
/*
n<=10
O((n!)n)
n=10 4e7 400ms
8
*/
