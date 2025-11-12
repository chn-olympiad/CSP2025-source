#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=0;
int n,a[5010];
long long ste(long long n){
	long long st=1;
	for(long long i=2;i<=n;i++){
		st*=i;
		st%=mod;
	}
	return st%mod;
}
long long C(long long n,long long m){
	long long ans=ste(n)%mod/(ste(m)%mod*ste(n-m)%mod);
	return ans%mod;
}
int ind=0,count_stick=0;
long long summary=0,maxn=0,stick[100];
void dfs(){
	if(ind==n){
		if(summary>2*maxn&&count_stick>=3)ans++;
		return ;
	}
	ind+=1;
	dfs();
	ind-=1;
	count_stick+=1;
	summary+=a[ind];
	int before_max=maxn;
	if(a[ind]>maxn)maxn=a[ind];
	stick[count_stick]=a[ind];
	ind+=1;
	dfs();
	stick[count_stick]=0;
	ind-=1;
	count_stick-=1;
	summary-=a[ind]; 
	maxn=before_max;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int one_j=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1)one_j=0;
	}
	if(one_j){
		for(int i=3;i<=n;i++){
			ans+=C(n,i)%mod;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	dfs();
	cout<<ans;
	return 0;
}
