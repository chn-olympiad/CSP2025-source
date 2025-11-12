#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510];
long long ans=0;
bool vis[510];
void dfs(int dep,int nowwl,int nowwd,int nownode){
	if(nowwl==m){
		long long hk=1;
		for(int i=1;i<=(n-dep+1);i++){
			hk=hk*i%998244353;
		}
		ans=(ans+hk)%998244353;
		return ;
	}
	if(dep>n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(c[i]>nowwd&&s[dep-1]=='1'){
				dfs(dep+1,nowwl+1,nowwd,nownode);
			}
			else{
				if(c[i]<=nowwd){
					int t;
					for(t=1;t<=i;t++){
						if(c[t]==c[i]){
							break;
						}
					}
					dfs(dep+1,nowwl,nowwd+1,t);
				}
				else dfs(dep+1,nowwl,nowwd+1,nownode);
			}
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	dfs(1,0,0,1);
	printf("%lld",ans);
	return 0;
}



