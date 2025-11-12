#include<bits/stdc++.h>
int t,n,a[100009][5],sum;
void dfs(int k,int ans,int g,int b,int c){
	if(k==n+1){
		if(g<=n/2&&b<=n/2&&c<=n/2){
			sum=std::max(sum,ans);
		}
		return ;
	}else{
		if(a[k][1]<a[k][2]){
			if(a[k][1]<a[k][3]){
				if(a[k][2]>a[k][3]){
					dfs(k+1,ans+a[k][2],g,b+1,c);
					dfs(k+1,ans+a[k][3],g,b,c+1);
				}else{
					dfs(k+1,ans+a[k][3],g,b,c+1);
					dfs(k+1,ans+a[k][2],g,b+1,c);
				}
			}else{
				dfs(k+1,ans+a[k][2],g,b+1,c);
				dfs(k+1,ans+a[k][1],g+1,b,c);
			}
		}else{
			if(a[k][2]<a[k][3]){
				if(a[k][3]>a[k][1]){
					dfs(k+1,ans+a[k][3],g,b,c+1);
					dfs(k+1,ans+a[k][1],g+1,b,c);
				}else{
					dfs(k+1,ans+a[k][1],g+1,b,c);
					dfs(k+1,ans+a[k][3],g,b,c+1);
				}
				
			}else{
				dfs(k+1,ans+a[k][1],g+1,b,c);
				dfs(k+1,ans+a[k][2],g,b+1,c);
			}	
		}
		return ;
	}
}
bool best(int k,int ans,int g,int b,int c){
	if(k==n+1){
		if(g<=n/2&&b<=n/2&&c<=n/2){
			sum=std::max(sum,ans);
			return true;
		}
		return false;
	}else{
		if(a[k][1]<a[k][2]){
			if(a[k][1]<a[k][3]){
				if(a[k][2]>a[k][3]){
					return best(k+1,ans+a[k][2],g,b+1,c);
				}else{
					return best(k+1,ans+a[k][3],g,b,c+1);
				}
			}else{
				return best(k+1,ans+a[k][2],g,b+1,c);
			}
		}else{
			if(a[k][2]<a[k][3]){
				if(a[k][3]>a[k][1]){
					return best(k+1,ans+a[k][3],g,b,c+1);
				}else{
					return best(k+1,ans+a[k][1],g+1,b,c);
				}
				
			}else{
				return best(k+1,ans+a[k][1],g+1,b,c);
			}	
		}
	}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int x=1;x<=t;x++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			scanf("%d",&a[i][3]); 
		}
		if(best(1,0,0,0,0)){
			printf("%d",sum);
		}else{
			sum=0;
			dfs(1,0,0,0,0);
			printf("%d",sum);
		}
		sum=0;
	}
	return 0;
}