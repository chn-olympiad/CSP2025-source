#include<bits/stdc++.h>
using namespace std;
const int N=5005;
bool vis[N];
int ans[N];
int cnt=0;
const int mod=998244353;
int n;

int a[N];
void dfs(int r,int dep){
	if(r==dep){
		int maxn=0,s=0;
		for(int i=1;i<=dep;i++){
			maxn=max(maxn,a[ans[i]]);
			s+=a[ans[i]];
		}
		//for(int i=1;i<=dep;i++){
		//		printf("%d ",ans[i]);
		//	}
		//	puts("");
		if(s>maxn*2){
			cnt++;
			cnt%=mod;
			
			
		}return;
	}
	for(int i=ans[dep]+1;i<=n;i++){
		ans[dep+1]=i;
		dfs(r,dep+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		memset(ans,0,sizeof(ans));
		
		dfs(i,0);
	}
	cout<<cnt;
	return 0;
}
