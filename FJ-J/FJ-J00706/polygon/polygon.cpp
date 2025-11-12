#include<bits/stdc++.h>
using namespace std;
#define L long long
const int N=1e4+10;
const int M=998244353;
L a[N],ans=0,n;
void dfs(L step,L maxx,L summ,L nw){
	if(step==n+1){
		if(nw>=3 && summ>2*maxx)
			ans++;
		ans%=M;
		return;
	}
	dfs(step+1,max(maxx,a[step]),summ+a[step],nw+1);
	dfs(step+1,maxx,summ,nw);
}
int main(){
	//freopen("polygon3.in","r",stdin);
	//freopen("polygon3.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=25){
		dfs(1,0,0,0);
		cout<<ans%M;
	}
	else{
		long long ans=0,sum=1,nw=2;
		while(nw<=n-2){
			ans+=sum;
			ans%=M;
			sum*=nw;
			sum%=M;
			nw++;
		}
		cout<<ans;
	}
	return 0;
}
