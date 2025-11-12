#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
int dp[500500];
int k,x;
int ans;
int xo(int i){
	if(dp[i]!=0)return dp[i];
	int m=0;
	int ci=0;		
	int maxx=0;
	for(int j=i;j<n;j++){
		m=m^a[j];	
		if(m==k){
			ci=1;
			for(int t=j+1;t<n;t++){
				maxx=max(maxx,xo(t));
			}	
		}
			
	}
	dp[i]=max(dp[i],maxx+ci);
	return maxx+ci;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a.push_back(x);	
	}
	for(int i=0;i<n;i++){
		if(dp[i]==0)ans=max(ans,xo(i));
		else break;
	}
	printf("%d",ans);
	return 0;
}

