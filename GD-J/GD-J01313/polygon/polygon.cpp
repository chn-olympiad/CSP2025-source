#include<bits/stdc++.h>
using namespace std;
int a[5005],cnt,r[5005],n;
void dfs(int cur){
	if(cur==0){
		int count_=1,maxxx=-2e9,summ=0;
		for(int i=1;i<=n;i++)if(r[i]==1)count_++,maxxx=max(maxxx,a[i]),summ+=a[i];
		cnt+=(count_>=3&&summ>2*maxxx);
		return;
	}
	for(int x=0;x<=1;x++){
		r[cur]=x;
		dfs(cur-1);
		r[cur]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int flag=1,maxx=-2e9,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],flag=(flag&&(a[i]==1)),maxx=max(maxx,a[i]),sum+=a[i];
	if(n==3){cout<<(sum>2*maxx)<<"\n";return 0;}
	if(flag){long long ans=1;for(int i=1;i<=n;i++)ans*=2,ans%=998244353;cout<<(ans-1-n-(n-1)*n/2)%998244353<<"\n";}
	else{
		dfs(n);
		cout<<cnt%998244353<<"\n";
	}
	return 0;
}
