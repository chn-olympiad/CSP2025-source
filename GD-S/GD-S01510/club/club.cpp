#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int T;
const int N=1e5+10;
int a[N][4];
int ans;
void find(int u,int sum,int t1,int t2,int t3){
	if(t1>n/2||t2>n/2||t3>n/2) return ;
	if(u>n){
		ans=max(ans,sum);
		return ;
	}
	find(u+1,sum+a[u][1],t1+1,t2,t3);
	find(u+1,sum+a[u][2],t1,t2+1,t3);	
	find(u+1,sum+a[u][3],t1,t2,t3+1);	
	}
void baoli();
void start(){
	ans=0;
	scanf("%lld",&n);
	if(n>=30){
		baoli();
		return ;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	}
	find(1,0,0,0,0);
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		start();
	}	
}
void baoli(){
	priority_queue<int> q;
	int sum=0;
		for(int i=1;i<=n;i++){
			int x,awa,qwq;
			scanf("%lld%lld%lld",&x,&awa,&qwq);
			q.push(x);
		}
		for(int i=1;i<=n/2;i++){
			sum+=q.top();
			q.pop();
		}
		printf("%lld\n",sum);
}
