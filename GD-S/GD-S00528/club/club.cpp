#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int T;
int n;
ll mas;
int st[100005][5];
int q[5];
void dfs(int x,ll y){
	if(x>n){
		mas=max(mas,y);
		return;
	}
	for(int i=1;i<=3;i++){
		if(q[i]+1>n/2){
			continue;
		}
		q[i]++;
		dfs(x+1,y+st[x][i]);
		q[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		mas=INT_MIN;
		memset(q,0,sizeof(q));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&st[i][1],&st[i][2],&st[i][3]);
		}
		
		dfs(1,0);
		printf("%lld\n",mas);
	}
	
	return 0;
}
