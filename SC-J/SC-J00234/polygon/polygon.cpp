#include<bits/stdc++.h>
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 5e3+5;

bool vis[N];
int n,a[N],res;

void dfs(const int& x,const int& sum,const int& max,const int& y);

signed main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	
	for(int i=3;i<=n;i++){
		dfs(i,0,0,1);
	}
	
	std::cout<<res;
	return 0;
}

void dfs(const int& x,const int& sum,const int& max,const int& y){
//	std::cout<<x<<" "<<sum<<" "<<max<<" "<<y<<"\n";
	if(y==n+1)return;
	for(int i=y;i<=n;i++){
		if(x==1){
			if(sum+a[i]>std::max(max,a[i])*2){
				res++;
			}
			continue;
		}
		dfs(x-1,sum+a[i],std::max(max,a[i]),i+1);
	}
}