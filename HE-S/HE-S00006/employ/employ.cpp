#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,dp[N][7],a[N][5],cnt,ans;
bool flag[7];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
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



