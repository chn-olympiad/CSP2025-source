#include<bits/stdc++.h>
using namespace std;
int a[500005],x[500005],dp[500005],b[500005];
unordered_map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x[1]=a[1];
	for(int i=2;i<=n;i++){
		int t=x[i-1];
		t^=a[i];
		x[i]=t;
	}
	for(int i=1;i<=n;i++){
		int kk=x[i];
		kk^=k;
		b[i]=kk;
	}
	mp.clear();
	mp[x[0]]=0;
	for(int i=1;i<=n;i++){
		/*int ans=-1;
		for(int j=i-1;j>=0;j--){
			if(x[j]==b[i]){
				ans=j;
				break;
			}
		}
		if(ans!=-1){
			dp[i]=max(dp[i-1],dp[ans]+1);
		}
		else{
			dp[i]=dp[i-1];
		}
		*/
		int ans=mp[b[i]];
		if(b[i]!=0&&ans==0)ans=-1;
        if(ans!=-1){
			dp[i]=max(dp[i-1],dp[ans]+1);
		}
		else{
			dp[i]=dp[i-1];
		}
		mp[x[i]]=i;
	}
	cout<<dp[n];
    return 0;
}
