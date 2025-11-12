#include<bits/stdc++.h>
using namespace std;
int n,a[5010],k,q[5010];
long long ans,tmp;
void bfs(int t,int total,int m,int c){
	if(t==k&&total>2*m){
		ans=(ans+1)%998244353;
		return ;
	}
	for(int i=c;i<=n;i++){
		//bfs(t+1,total+a[i],max(m,a[i]),i);
		if(q[i]==0){
			q[i]=1;
			bfs(t+1,total+a[i],max(m,a[i]),i);
			q[i]=0;
		}
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(k=3;k<=n;k++){
		bfs(0,0,0,1);
	}
	cout<<ans;
	return 0;
}

