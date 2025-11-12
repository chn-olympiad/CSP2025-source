#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,dp[N][7],a[N][5],cnt;
bool flag[7];
int main(){
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		int x1,x2,x3;
    		cin>>x1>>x2>>x3;
    		if(x1>x2 and x1>x3){
    			if(t[1]>=n/2){
    				if(x2>x3){
    					if(t[2]>=n/2){
    						continue;
						}
						else{
							ans+=x2;
						}
					}
					else{
						if(t[3]>=n/2)
						continue;
						else{
							ans+=x3,t[2]++;
						}
					}
				}
				else{
					ans+=x3,t[3]++;
				}
			}
		}
		cout<<ans<<endl;	
	}
}

for(int i=1;i<=n;i++){
	for(int j=1;j<=4;j++){
		if(flag[j]){
			int maxn=0;
			for(int k=1;k<=4;k++){
				if(k==j){
					continue;
				}
				maxn=max(maxn,dp[i][k]);
			}
			dp[i][j]=maxn+a[i][j];
		}
		else{
			int maxn=0;
			++cnt[j];
			if(cnt[j]>n/2){
				flag[j]=1;
			}
			for(int k=1;k<=4;k++){
				maxn=max(maxn,dp[i][k]);
			}
			dp[i][j]=maxn+a[i][j];
		}
	}
}
