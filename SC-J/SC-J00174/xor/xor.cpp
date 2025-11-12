#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,ans=0;
long long a,s[N],dp[N],cnt=0;
struct f{
	int l;
	int r;
}f[N];
bool cmp(struct f x,struct f y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long p=s[j]^s[i-1];
			if(p==k){
				f[cnt].l=i;
				f[cnt].r=j;
				cnt++;
			}
		}
	}
	for(int i=0;i<=cnt;i++){
		dp[i]=1;
	}
	sort(f,f+cnt,cmp);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<i;j++){
			if(f[j].r<f[i].l) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	for(int i=0;i<cnt;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}