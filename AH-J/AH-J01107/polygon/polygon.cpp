#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool used[5005];
void dfs(int i,int s,int z,int mx){
	if(i==s+1){
		if(z>mx*2) ans++;
		return ;
	}
	for(int j=i;j<=n;j++){
		if(used[j]==0){
			used[j]=1;
			dfs(i+=1,s,z+a[j],max(mx,a[j]));
			used[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		memset(used,0,sizeof(used));
		dfs(1,i,0,0);
	}
	printf("%d\n",ans);
}
