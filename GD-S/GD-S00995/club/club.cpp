#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100,M=300;
int n,s[N][4],a[N],idl[4];//三个部门，对于每个人可以有选或者不选 
int dfs(int i){
	if(i>n)return 0;
	int res=0;
	for(int j=1;j<=3;j++){
		if(idl[j]<(n/2)){
			idl[j]++;
			res=max(res,dfs(i+1)+s[i][j]);
			idl[j]--;
		}
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		bool vis=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
			if(s[i][2]==1||s[i][3]==1)vis=1;
			a[i]=s[i][1];
		}
		sort(a+1,a+1+n);
		if(vis==0){
			int res=0;
			for(int i=n;i<=n/2;i++){
				res+=a[i];
			}
			printf("%d\n",res);
		}else{
			printf("%d\n",dfs(1));
		}
	}
	
	
	return 0;
} 
