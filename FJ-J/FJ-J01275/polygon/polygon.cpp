#include<bits/stdc++.h>
using namespace std;
long long a[5050],b[5050],n,ans,sum,st;
bool bo=1;
bool cmp(long long a,long long b){
	return a>b;
}
bool dfs(long long c){
	if(sum>a[st]){
		ans=(ans+(b[n-c]%998244353))%998244353;
		return 0;
	}
	for(long long i=c+1;i<=n;i++){
		if(c==n){
			return 1;
		}
		if(c==0){
			st=i;
		}
		else{
			sum+=a[i];
		}
		long long x=c;
		c=i; 
		bool bb=dfs(i);
		c=x;
		if(c!=0){
			sum-=a[i];
		}
		if(c!=0&&bb){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			bo=0;
		}
	}
	if(bo){
		long long po=1;
		for(long long i=0;i<n;i++){
			po*=2;
			po%=998244353;
		}
		cout<<(po-((n*(n-1))/2)%998244353-n-1)%998244353;
		return 0;
	}
	b[0]=1;
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]*2;
	}
	sort(a+1,a+n+1,cmp);
	dfs(0);
	cout<<ans;
	return 0;
} 
