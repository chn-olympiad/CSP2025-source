#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],q[500005],sum,cnt,dp[500005];
bool f=1;
struct ss{
	int l,r; 
}s[500005];
bool operator<(ss x,ss y){
	return x.r<y.r||(x.r==y.r&&x.l<y.l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=0;
	}
	if(f){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
				else if(a[i+1]==1){
					sum++;i++;
				}
			}
		}else if(k==1){
			for(int i=1;i<=n;i++)
				if(a[i]==1)sum++;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(q[i-1]^q[j]==k){
				s[++cnt].l=i;
				s[cnt].r=j;
			}
	sort(s+1,s+cnt+1);
	for(int i=1;i<=cnt;i++)dp[i]=1;
	for(int i=2;i<=cnt;i++)
		for(int j=1;j<i;j++)
			if(s[i].l>s[j].r)dp[i]=max(dp[i],dp[j]+1);
			else dp[i]=max(dp[i],dp[j]);
	cout<<dp[cnt];
	return 0;
}
