#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long n,a[5005],ans=0,q[5005];
void dfs(long long num,long long zlen,long long mlen,long long zz){
	if(zz>=3&&zlen>mlen*2){
		ans++;
		ans%=N;
	}
	if(num==n+1)
		return;
	for(long long i=num;i<=n;i++){
		dfs(i+1,zlen+a[i],max(mlen,a[i]),zz+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxn=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	q[0]=1;
	if(maxn==1){
		long long ans1=0;
		for(long long i=3;i<=n;i++){
			if(n-i>i){
				long long sum1=1,sum2=1;
				for(long long j=1;j<=i;j++){
					sum1*=j;
					sum1%=N;
				}
				for(long long j=n-i+1;j<=n;j++){
					sum2*=j;
					sum2%=N;
				}
				ans1+=((sum2/sum1)%N);
			}
			else{
				long long sum1=1,sum2=1;
				for(long long j=1;j<=n-i;j++){
					sum1*=j;
					sum1%=N;
				}
				for(long long j=i+1;j<=n;j++){
					sum2*=j;
					sum2%=N;
				}
				ans1+=((sum2/sum1)%N);
			}
		}
		cout<<ans1%N;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);                                  
	cout<<ans%N;
	return 0;
}