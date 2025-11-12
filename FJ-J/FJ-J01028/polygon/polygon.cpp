#include<bits/stdc++.h>
using namespace std;
long long a[5003],n,sum=0,cnt=0,ans=0,ma=0;
void dfs(int k,int m){
	if(k==n+1){
		if(ans>=3&&sum>ma*2){
			cnt+=1;
		}
		return;
	}
	ans+=1; 
	sum+=a[k];
	ma=a[k];
	dfs(k+1,k);
	ans-=1;
	sum-=a[k];
	ma=a[m];
	dfs(k+1,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=0;
	dfs(1,0);
	cnt%=998244353;
	cout<<cnt;
	return 0;
}
