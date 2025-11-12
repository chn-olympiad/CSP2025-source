#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],f[4],maxx; 
vector <int> v[4];
void dfs(int k,int sum){
	bool flag=0;
	for(int i=1;i<=3;i++){
		if(f[i]<n/2){
			flag=1;
			f[i]++;
			v[i].push_back(a[k][i]);
			dfs(k+1,sum+a[k][i]);
			f[i]--;
		}
	}
	if(flag==0){
		maxx=max(sum,maxx);
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int m=1;m<=t;m++){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		maxx=-1;
		dfs(1,0);
		printf("%d\n",maxx);
	}
	return 0;
}
