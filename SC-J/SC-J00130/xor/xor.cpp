#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct qj{
	int l,r;
}q[1010];
long long a[1010],dp[1010][1010];
bool cmp(qj a,qj b){
	if(a.r==b.r) return a.l>b.l;
	return a.r<b.r; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			int l=j,r=i+j-1;
			dp[l][r]=dp[l][r-1] xor a[r];
			if(dp[l][r]==k){
				cnt++;
				q[cnt].r=r;
				q[cnt].l=l;
				//cout<<l<<" "<<r<<endl;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int ans=0,s=-1e9;
	for(int i=1;i<=cnt;i++){
		if(q[i].l<=s) continue;
		ans++;
		s=q[i].r;
	}
	cout<<ans;
	return 0;
}