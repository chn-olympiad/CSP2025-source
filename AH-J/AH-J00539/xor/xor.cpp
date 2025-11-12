#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long dp[500005][2];
struct node{
	int l,r;
}b[1000005];
bool cmp(node A,node B){
	if(A.l!=B.l)return A.l<B.l;
	else return A.r<B.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,t=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[++t].l=i;
			b[t].r=i;
		}
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			long long sum=a[i];
			for(int j=i+1;j<=n;j++){
				sum^=a[j];
				if(sum==k){
					b[++t].l=i;
					b[t].r=j;
				}
			}
		}
		sort(b+1,b+1+t,cmp);
		dp[1][1]=1;
		for(int i=2;i<=t;i++){
			for(int j=i-1;j>=1;j--){
				dp[i][0]=max(dp[i][0],max(dp[j][1],dp[j][0]));
				dp[i][1]=max(dp[i][1],dp[j][0]);
				if(b[i].l>b[j].r) dp[i][1]=max(dp[i][1],dp[j][1]+1);
			}
		}
		cout<<max(dp[t][0],dp[t][1])<<'\n';
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans<<'\n';
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
		    if(a[i]==0)ans++;
		    else{
				int cnt=0;
				while(a[i]==1){
					i++;
					cnt++;
				}
				ans+=cnt/2;
				i--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
