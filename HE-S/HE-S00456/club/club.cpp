#include<bits/stdc++.h>
using namespace std;
int t,n,s[100010][4],b[100010];

long long dfs(int x,int a,int b,int c){
	
	if(a>n/2||b>n/2||c>n/2){
		return -1;
	}
	
	if(x==n+1){
		return 0;
	}
	long long ans1=dfs(x+1,a+1,b,c);
	long long ans2=dfs(x+1,a,b+1,c);
	long long ans3=dfs(x+1,a,b,c+1);
	long long ans=(ans1+s[x][1],max(ans2+s[x][2],ans3+s[x][3]));
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.txt","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&s[i][j]);
			}
		}	
		printf("%lld",dfs(1,0,0,0));
	}
}
