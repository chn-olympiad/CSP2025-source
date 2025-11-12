#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
long long dp[1000005][2];
long long n,k;
struct ll{
	long long l,r;
}s[1000005];
void solve1(){
	cout<<n/2;
}
void solve2(){
	long long p=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((pre[j-1]^pre[i])==k){
				p++;
//				cout<<i<<"  "<<j<<endl;
				s[p].l=j;
				s[p].r=i;
			}
		}
	}
	long long ans=0;
//	cout<<p<<endl;
	for(int i=1;i<=p;i++){
		for(int j=i+1;j>=1;j--){
//			cout<<i<<" "<<j<<endl;
			if(s[i].l<=s[j].r&&s[i].r>=s[j].r){
				dp[i][0]=max(dp[j][1],dp[i][0]);
			}else{
				dp[i][1]=max(dp[j][1]+1,dp[i][1]);
				dp[i][1]=max(dp[j][0]+1,dp[i][1]);
			}
		} 
		ans=max(dp[i][1],ans);
		ans=max(dp[i][0],ans);
	}
	cout<<ans;
}
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>k;
	long long cnt=0;
	long long cnt2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			cnt++;
			if(a[i]!=0){
				cnt2++;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
//		cout<<pre[i]<<" dfgfdg"<<endl;
	}
	if(cnt==0){
		solve1();
	}else{
		solve2();
	}
	return 0;
}