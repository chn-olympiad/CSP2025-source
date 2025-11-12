#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long num=0;
long long jc(long long x){
	long long sum=1;
	for(long long i=1;i<=x;i++){
		sum*=i;
		sum%=998244353;
	}
	return sum; 
}
long long cl(long long a,long long b){
	long long y=(jc(a)*jc(b-a))%998244353;
	return jc(b)/y;
}
void dfs(int pos,int sum,long long he,long long ma){
	if(pos>n){
		if(sum<3)return;
		if(he>2*ma)num++;
		num%=998244353;
		return;
	}
	dfs(pos+1,sum+1,he+a[pos],max(ma,a[pos]));
	dfs(pos+1,sum,he,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n]==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=cl(i,n);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<num;
	return 0;
}
