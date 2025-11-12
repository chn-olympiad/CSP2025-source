#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N][10],w[10];
int am[N];
bool tr=false;
int n,t,maxn,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;tr=false;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
			cin>>a[j][k];
			if(a[j][2]==0&&a[j][3]==0){tr=true;am[j]=a[j][1];
			}
		  }
		}
		if(tr){
			sort(am+1,am+1+n);
			for(int j=n;j>n/2;j--){
			  ans+=am[j];
			}

			cout<<ans;
			continue;
		}

	}
	return 0;
}
/*memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++){
			for(int k=3;k>=1;k--){
				if(w[k]>n/2)
				  continue;
				else{
				dp[j]=max(dp[j],dp[j-1]+a[j][k]);w[k]++;}
			}
		}
		cout<<dp[n]<<endl;  //bag problem*/
