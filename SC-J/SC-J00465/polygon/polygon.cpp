#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long ans=0;
int n;
void dfs(int id,int mx,int sum,int s,bool f){
    if(sum>2*mx&&s>=3&&f==0){
    	f=1;
		ans++;
	}
	if(id==n+1){
	    return ;
	}
	dfs(id+1,max(mx,a[id]),sum+a[id],s+1,0);
	dfs(id+1,mx,sum,s,f);
}
int cnt=1;
long long qpow(long long a,long long b,long long p){
	cnt++;
	long long ans=1;
	if(b%2==1){
		ans=a;
	}
	if(b==1){
		return a;
	}
	ans*=qpow(a,b/2,p)*qpow(a,b/2,p)%p;
	return ans;
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
	}
	if(n<=20){
		dfs(1,0,0,0,0);
		cout<<ans;
	}else{
		long long c1=n;
		long long c2=n*(n-1)/2;
		c2%=998244353;
		cout<<qpow(2,n,998244353)-c1-c2-1;
	}
	return 0;
}