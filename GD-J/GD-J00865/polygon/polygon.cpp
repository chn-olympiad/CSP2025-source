#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N=5005,M=998244353;

int a[N],v[N],k,n,maxk=0;
long long ans=0;

long long qpow(int n,int k){
	long long res=1,a=n;
	while(k){
		if(k&1){
			res*=a;res%=M;
		} k>>=1;a*=a;a%=M; 
	}
	return res;
}

void dfs(int k,int mk,int cnt,int sum){
	if(k>n){
		if(cnt>=3&&sum>2*mk){
			ans++;ans%=M; 
		}
		return;
	}
	v[k]=0;
	dfs(k+1,mk,cnt,sum);
	v[k]=1;
	dfs(k+1,max(mk,a[k]),cnt+1,sum+a[k]);
	return;
}

long long C(int n,int m){
	long long res=1;
	if(n-m<m) m=n-m;
	for(long long i=n;i>=n-m+1;i--){
		res*=i;res%=M;
	}
	for(long long i=m;i>=2;i--){
		res*=qpow(i,M-2);res%=M;
	}
	return res;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];maxk=max(maxk,a[i]);
	} 
	if(maxk==1){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);ans%=M;	
		} 
		cout<<ans<<endl;
		return 0;
	}
	ans=0;
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
