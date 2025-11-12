#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5010],vis[5010],cnt=0,c[5010];
long long n;
bool check(){
	long long num=0,sum=0,maxd=0;
	for(long long i=1;i<=n;i++){
		if(vis[i]==1){
			vis[i]=0;
			num++;
			sum+=a[i];
			maxd=max(a[i],maxd);
		}
	}
	if(num>=3&&sum>2*maxd) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxd=0;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxd=max(maxd,a[i]);
	}
	if(maxd==1){
		int sum=0;
		c[0]=1;
		c[1]=n;
		for(int i=2;i<=n-3;i++){
			c[i]=c[i-1]*(n-i+1)/i;
		}
		for(int i=0;i<=n-3;i++) sum+=c[i];
		cout<<sum;
		return 0;
	}
	
	for(long long i=0;i<(1<<n);i++){
		for(long long j=0;j<=n;j++){
			if(i&(1<<j)){
				vis[j+1]=1;
			}
		}
		if(check()){
			cnt++;
			cnt%=mod;
		}
	}
	cout<<cnt;
}