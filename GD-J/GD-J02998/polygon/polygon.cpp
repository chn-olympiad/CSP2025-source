#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans,vis,flag,s[5005],c;
void dfs(int x,int stp,int t,int q){
	//cout<<x<<" "<<stp<<" "<<t<<" "<<ans<<endl;
	if(x==q){
		if(stp>t){
			ans++;
			ans%=998244353;
		}
		return;
	}
	s[++c]=x;
	dfs(x+1,stp+a[x],t,q);
	c--;
	flag=1;
	dfs(x+1,stp,t,q);
	flag=0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(i>=3&&a[i]<sum[i-1]){
			dfs(1,0,a[i],i);
			//cout<<i<<endl;
		}
	}
	printf("%d",ans);
}//1 2 3 4 5
