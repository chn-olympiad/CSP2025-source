#include<bits/stdc++.h>
using namespace std;
long long n,x[5005],a[5005];
long long cnt;
inline void dfs(int k,int m){
	if(k==m+1){
		long long sum=0,ma=0;
		for(int i=1;i<=m;i++){
			ma=max(ma,x[a[i]]);
			sum+=x[a[i]];
		}
		if(sum>ma*2){
			cnt++;
			cnt%=998242353;
		}
	}else{
		for(int i=a[k-1]+1;i<=n;i++){
			a[k]=i;
			dfs(k+1,m);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<cnt;
	return 0;
}
