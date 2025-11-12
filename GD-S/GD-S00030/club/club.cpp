#include <bits/stdc++.h>

using namespace std;
int a[100005][4],n,cnt[4],ma=-1;
int dfs(int cur,int sum){
	
	if(cur==n+1){
					
        
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
		ma=max(ma,sum);
		
		return sum;
		}else{
			return -1;
		}
	}
	for(int i=cur;i<=n;i++){
		for(int j=1;j<=3;j++){
			cnt[j]++;
			
			dfs(i+1,sum+a[i][j]);
			cnt[j]--;

		}
	}
	return ma;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;

	
	while(t--){
		cin>>n;
	for(int i=1;i<=n;i++){
      	for(int j=1;j<=3;j++){
		cin>>a[i][j];	
     	}				
	}
	dfs(1,0);
   cout<<ma;
   ma=-1;
	}
	return 0;
} 


