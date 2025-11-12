#include<bits/stdc++.h>
using namespace std;
int dp[500005];
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
    cin>>n>>k;
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
	}
    int check=INT_MAX;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=i;j>=1;j--){
            if(check==j){
                dp[i]=dp[check];
                break;
            }
            if(int(a[j] ^ tmp)==k){
                dp[i]=dp[j-1]+1;
                check=i;
                break;
            }
            tmp^=a[j];
        }
    }
    cout<<dp[n];
	return 0;
}
