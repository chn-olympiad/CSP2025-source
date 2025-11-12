#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],dp[N],yong[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int dp1[n+5][n+5];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		dp1[i][i]=a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp1[i][j]=(dp1[i][j-1])^(a[j]);
			//cout<<dp1[i][j]<<" "; 
		}
		//cout<<endl;
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp1[i][j]==k){
				bool flag=true;
				for(int x=i;x<=j;x++){
					if(yong[x]==1){
						flag=false;
					}
				}
				if(flag){
					cnt++;
					for(int x=i;x<=j;x++)yong[x]=1;
				}
			}
		}
	} 
    cout<<cnt;
	return 0;
}
