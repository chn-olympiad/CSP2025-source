#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[100005][4];
int dp[705][705][705];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		bool sf=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(!(a[i][2]==0 && a[i][3]==0) ){
				sf=false;
			}
		}
		
		if(sf){
			int b[100005];
			b[0]=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<'\n';
			return 0;
		}
		
		memset(dp,0,sizeof dp);
		
		for(int i=1;i<=n;i++){
		for(int w1=n/2;w1>=0;w1--){
			for(int w2=n/2;w2>=0;w2--){
				for(int w3=n/2;w3>=0;w3--){
					
						if(w1>0) dp[w1][w2][w3]=max(dp[w1][w2][w3],dp[w1-1][w2][w3]+a[i][1]);
						if(w2>0) dp[w1][w2][w3]=max(dp[w1][w2][w3],dp[w1][w2-1][w3]+a[i][2]);
						if(w3>0) dp[w1][w2][w3]=max(dp[w1][w2][w3],dp[w1][w2][w3-1]+a[i][3]);
					}
				}
			}
		}
//		for(int w1=0;w1<=n/2;w1++){
//			for(int w2=0;w2<=n/2;w2++){
//				for(int w3=0;w3<=n/2;w3++){
//					cout<<w1<<' '<<w2<<' '<<w3<<' '<<dp[w1][w2][w3]<<'\n';
//				}
//			}
//		}
		cout<<dp[n/2][n/2][n/2]<<'\n';
	} 
	return 0;
}
