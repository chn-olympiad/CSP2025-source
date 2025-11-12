#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s=0,b[5005];
void dfs(long long k,long long sum,long long w,long long r){
	if(k>sum*2){
		s++;
		s=s%998244353;
	}
	for(int i=r;i<=w;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(k+a[i],sum,w,i);
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		dfs(0,a[i],i,1);
	}
	cout<<s%998244353;
}
