#include<bits/stdc++.h>
using namespace std;
long long t,n,ma;
long long a[100005][5];
void dfs(int cnt,int x,long long ans,int aa,int bb,int cc){
	if(cnt>=n){
		if(aa<=n/2&&bb<=n/2&&cc<=n/2){
			ma=max(ma,ans);
		}
		return ;
	}
	if(aa+1<=n/2){
		dfs(cnt+1,x+1,ans+a[x][1],aa+1,bb,cc);
	}
	if(bb+1<=n/2){
		dfs(cnt+1,x+1,ans+a[x][2],aa,bb+1,cc);
	}
	if(cc+1<=n/2){
		dfs(cnt+1,x+1,ans+a[x][3],aa,bb,cc+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ma=0;
		cin>>n;
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=3;j++){
	    		cin>>a[i][j]; 
			}
		}
		dfs(0,1,0,0,0,0);
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
