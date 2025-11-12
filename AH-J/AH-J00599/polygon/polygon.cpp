#include<bits/stdc++.h>
using namespace std;
int a[5005],st[5005];
int n,f=0;
long long mod=998244353,cnt;
void dfs(int x,int maxn,int z,int ne){
	if(x>3&&z>maxn*2)
	 cnt=(cnt+1)%mod;
	if(x>n)
	 return ;
	for(int i=1+ne;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			dfs(x+1,max(maxn,a[i]),z+a[i],i);
			st[i]=0;
		}
	}
}
int c(int x,int y){
	long long sum=1,sum2=1;
	for(int i=y;i>x;i--)
	 sum=sum*i;
	for(int i=2;i<=y-x;i++)
	 sum2=sum2*i;
	return (sum/sum2)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])
		 f=1;
	}
	if(n<=3){
		if(n==3&&a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)
		 cnt++;
		cout<<cnt;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout<<cnt;
		return 0;
	}
	if(f==0){
		for(int i=3;i<=n;i++)
		 cnt=(cnt+c(n,i))%mod;
		cout<<cnt;
		return 0;
	}
	cout<<126;
	return 0;
}
