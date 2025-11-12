#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],sum1,ff,b[100001];
void dfs(long long i,long long sum,long long mx,long long cnt,long long f){
	if(sum>(mx*2)&&cnt>=3&&f!=0){
		sum1++;
	}
	if(i==n+1||cnt==n) return ;
	dfs(i+1,sum+a[i],max(mx,a[i]),cnt+1,1);
	dfs(i+1,sum,mx,cnt,0);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) ff=1;
	}
	if(ff==0){
		for(long long i=1;i<=n;i++){
			b[i]=b[i-1]+i;
		}
		for(long long i=3;i<=n;i++){
			for(long long j=i;n-j+1>=1;j++){
				sum1+=b[n-j+1];
			}
		}
		cout<<sum1;
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<sum1;
	return 0;
}
