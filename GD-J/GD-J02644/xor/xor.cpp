#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,len;
bool flag[500005];
int dp[500005];
int cnt1,cnt0;
struct node {
	int l,r;
} Xor[500005];
bool cmp(node a,node b) {
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0) cnt0++;
		else cnt1++;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int sum=0;
			for(int l=i; l<=j; l++) {
				sum^=a[l];
			}
			if(sum==k) {
				Xor[++len]= {i,j};
			}
		}
	}
	for(int i=1;i<=len;i++){
		dp[i]=1;
	}
	for(int i=1;i<=len;i++){
		for(int j=1;j<i;j++){
			if(Xor[j].r<Xor[i].l) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<dp[len];

//	cout<<x;
}
/*
#Shang4Shan3Ruo6Shui4
*/
