#include<bits/stdc++.h>
using namespace std;
int a[100009][4],t,n,ans,c[4];
void dfs(int m,int s){
	if(m>n){
		ans = max(s,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i] < n/2){
			c[i]+=1;
			dfs(m+1,s+a[m][i]);
			c[i]-=1;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
