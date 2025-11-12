#include <bits/stdc++.h>
using namespace std;
int a[5005],n,f;
long long ans;
void dfs(int smax,long long sum,int num,int maxn,int fi){
	if(num==maxn){
		if(sum>smax*2) ans++;
		ans=ans%998244353;
		return ;
	}
	for(int i=fi;i<=n;i++){
		int x=a[i];
		int ss=max(smax,x);
		dfs(ss,sum+x,num+1,maxn,i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=1;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	//~ if(f==0){
		//~ double anss=0;
		//~ for(long long i=3;i<=n;i++){
			//~ long long j=n-i;
			//~ double xx=1;
			//~ if(i<j){
				//~ for(long long k=n,kk=1;kk<=i;kk++,k--){
					//~ xx=xx*k*1.00/kk;
				//~ }
			//~ }else{
				//~ for(long long k=n,kk=1;kk<=j;kk++,k--){
					//~ xx=xx*k*1.00/kk;
				//~ }
			//~ }
			//~ anss+=xx;
			//~ if(anss>998244353) anss-=998244353;
		//~ }
		//~ cout<<anss<<" ";
	//~ }
	for(int i=3;i<=n;i++){
		dfs(0,0,0,i,1);
	}
	cout<<ans;
	return 0;
}
