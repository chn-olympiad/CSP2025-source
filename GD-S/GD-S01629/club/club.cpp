#include <iostream>
#include <cstring>
using namespace std;

int n;
const int maxn=5*100000+10;
int a[maxn],b[maxn],c[maxn];
bool vis[maxn];
int ans=-1;

void dfs(int cur,int sum,int ca,int cb,int cc){
	if(cur==n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			if(ca+1<=n/2) {
				vis[i]=1;
				dfs(cur+1,sum+a[i],ca+1,cb,cc);
				vis[i]=0;
			}
			if(cb+1<=n/2){
				vis[i]=1;
				dfs(cur+1,sum+b[i],ca,cb+1,cc);
				vis[i]=0;
			} 
			if(cc+1<=n/2){
				vis[i]=1;
				dfs(cur+1,sum+c[i],ca,cb,cc+1);
				vis[i]=0;
			} 
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout)''
	int t;
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		memset(vis,0,sizeof(vis));
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
