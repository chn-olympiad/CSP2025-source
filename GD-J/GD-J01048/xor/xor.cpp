#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n,k,a[N],dp[N],mx;


int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) dp[i]=1;
		a[i]^=a[i-1];
		dp[i]+=dp[i-1];
	}
	for(int len=2;len<=n;len++){
		for(int l=1,r=len;r<=n;l++,r++){
			int x=a[l-1],y=a[r],cnt=0;
			vector<int> ans;
			while(x||y){
				ans.push_back(x%2!=y%2);
				x/=2,y/=2;
			}
			for(int i=ans.size()-1;i>=0;i--){
				cnt<<=1;
				cnt|=ans[i];
			}
			if(cnt==k) dp[r]=max(dp[r],dp[l-1]+1);
			else dp[r]=max(dp[r],dp[l-1]);
			mx=max(mx,dp[r]);
		}
	}
	cout<<mx<<"\n";
	return 0;
}
