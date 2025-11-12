#include<bits/stdc++.h>

using namespace std;

const int mod=998244353,N=5000;

#define ll long long
int n;
int a[N];
int ans;
int path[N];
int tot;
map <string,int> m;
void dfs(int x,int sum,int ma,int k,string t){
	//cout<<x<<" "<<sum<<" "<<ma<<" "<<k<<endl;
	if(k>=3){
		if(sum>ma*2){
			m[t]++;
			if(m[t]==1)
				ans=(ans+1)%mod;
			//cout<<x<<" "<<sum<<" "<<ma<<" "<<k<<endl;
		}
	}
	if(x==n+1) return ;
	dfs(x+1,sum+a[x],max(ma,a[x]),k+1,t+char(x));
	dfs(x+1,sum,ma,k,t);
}
long long c(int a){
	long long ans=1;
	for(int i=a+1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
	long long j=1;
	for(int i=1;i<=n-a;i++)
		j=(j*i)%mod;
	return (ans/j)%mod;
}
void solve(){
	long long sum=0;
	for(int i=3;i<n;i++){
		sum=(sum+c(i))%mod;
	}
	cout<<(sum+1)%mod<<endl;
	return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=1)
    		flag=false;
	}
    if(flag){
    	solve();
    	return 0;
	}
    dfs(1,0,0,0,"");
    cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

