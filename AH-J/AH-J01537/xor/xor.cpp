#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int a[500005];
node pr[500005];
int dp[1000005];
int cg[1000005];
int cnt,n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			num=num^a[j];
			if(num==k){
				++cnt;
				pr[cnt].l=i;
				pr[cnt].r=j;
				break;
			}
		}
	}
	//for(int i=1;i<=cnt;i++)cout<<pr[i].l<<pr[i].r<<endl;
	int maxn=0;
	for(int i=1;i<=cnt;i++){
		int l=pr[i].l,r=pr[i].r;
		maxn=max(maxn,r);
		for(int j=1;j<=maxn;j++){
			if(r<=j)
			dp[j]=max(cg[j],max(cg[l-1]+1,dp[j-1]));
			else
			dp[j]=max(cg[j],dp[j-1]);
			//cout<<i<<" "<<j<<" "<<dp[j]<<endl;
			
			
		}
		for(int j=0;j<=maxn;j++){
			cg[j]=dp[j];
		}
	}
	cout<<dp[maxn];
	return 0;
}
