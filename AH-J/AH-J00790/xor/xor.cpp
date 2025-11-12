#include<bits/stdc++.h>
using namespace std;
struct answer{
	int l,r;
}ans[500005];
int a[500005],dp[500005][2];
bool cmp(answer x,answer y){
	return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int o=a[i];
		if(o==k){
			ans[++num].l=i;
			ans[num].r=i;
		}
		for(int j=i+1;j<=n;j++){
			o^=a[j];
			if(o==k){
				ans[++num].l=i;
				ans[num].r=j;
			}
		}
	}
	sort(ans+1,ans+num+1,cmp);
	int m=INT_MIN;
	dp[0][1]=dp[0][0];
	for(int i=1;i<=num;i++){
		for(int j=i-1;j>=0;j--){
			if(ans[j].r<ans[i].l){
				dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+1);
				dp[i][0]=max(dp[i][0],max(dp[j][0],dp[j][1]));
			}
			//cout<<dp[i][1]<<" "<<dp[i][0]<<endl;
			m=max(m,dp[i][1]);
		}
	}
	cout<<m<<endl;
    return 0;
}
