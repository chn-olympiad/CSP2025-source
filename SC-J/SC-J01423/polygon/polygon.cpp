#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[1000000],sum=0,Max=0,ans=0,step=0;
bool b[1000000];
long long n;
void dfs(long long x){
	if(x>n) return;
	if(step>n) return;
	if(step>=3){
		if(sum>2*Max){
			ans++;
	    	ans%=mod;
	    	return;
		}
		else dfs(x+1);
	}else{
		for(int i=1;i<=n;i++){
			if(!b[i]){
				long long z=Max;
		    	sum+=a[i];Max=max(a[i],Max);step++;b[i]=true;
		    	dfs(i);
		    	sum-=a[i];Max=z;step--;b[i]=false;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans/2;
	return 0;
}