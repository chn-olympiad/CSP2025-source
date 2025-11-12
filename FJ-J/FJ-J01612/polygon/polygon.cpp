#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],ans=0,s=0,maxn=0,n,l=998244353;
int dfs(long long m,long long k){
	if(m>k){
	 ans++;
	 return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
		b[i]=1;
		dfs(m+1,k);
		b[i]=0;
		}
	}
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
	  for(int j=1;j<=i;j++){
	  	b[j]=0;
	  }
		dfs(1,i);
	}
	cout<<ans%l;
	return 0;
}