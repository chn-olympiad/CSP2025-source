#include<bits/stdc++.h>
using namespace std;
int n,Long[5005],ans;
bool vis[5005],visx[5005]; 
bool cmp(int x,int y){
	return x<y;
}
int summ,maxx;
bool flag,zj;
void dfs(int step,int startx){
	zj=false;
	if(summ>2*maxx){
		ans++;
		flag=true;
	}
	for(int i=n-1;i>=startx;i--){
		if(vis[i]==false){
			maxx=Long[i];
			summ+=Long[i];
			visx[i]=true;
			vis[i]=true;
			zj=true;
			if(i!=n-1){
				dfs(step+1,i);
			}else{
				
			}
			vis[i]=false;
			summ-=Long[i];
		}
	}
	if(zj==true){
		if(summ>2*maxx){
			ans++;
			return ;
		}	
	}
	else if(flag==true) return ;
	if(step>=n){
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&Long[i]);
		vis[i]=false;
	}
	sort(Long,Long+n,cmp);
	fill(vis,vis+n,false);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
