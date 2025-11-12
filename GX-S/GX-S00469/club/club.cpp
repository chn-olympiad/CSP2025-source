#include<bits/stdc++.h>
using namespace std;
/*struct club{
		int d1,d2,d3,id;
}a[100005];
*/
/*bool cmp(club x,club y){
	if(x.d1>y.d1)  return x.d1>y.d1;
	else{
		if(x.d2>y.d2) return x.d2>y.d2;
		else if(x.d3>y.d2) return x.d3>y.d3;
		else if(x.id<y.id) return x.id<y.id;
	}
	return 0;
}*/
struct du{
	int id,v;
}d1[100005],d2[100005],d3[100005];
int ans=0;
int n;
//int dp[205][105][105][105];
int dfs(int k,int w,int o,int p,int q){
	ans++;
	if(k>n){
		return w;
	} 
	else{	int res=0;
			if(o<n/2) res=max(dfs(k+1,w+d1[k].v,o+1,p,q),res);
			if(p<n/2) res=max(dfs(k+1,w+d2[k].v,o,p+1,q),res);
			if(q<n/2) res=max(dfs(k+1,w+d3[k].v,o,p,q+1),res);
			return res;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		//int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			cin>>d1[i].v>>d2[i].v>>d3[i].v;
			d1[i].id=d2[i].id=d3[i].id=i;
		}
		/*int dp[n+5][(n>>1)+5][(n>>1)+5][(n>>1)+5]={0};
		for(int i=1;i<=n;++i){
			for(int j=1;j<=(n>>1);++j){
				for(int k=1;k<=(n>>1);++k){
					for(int z=1;z<=(n>>1);++z){
						dp[i][j][k][z]=dp[i-1][j-d1[i].v][
		}
		}
		}
		}*/
		cout<<dfs(1,0,0,0,0)<<endl;
		ans=0;
	}
	
	return 0;
}


