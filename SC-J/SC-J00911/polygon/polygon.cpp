#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[2510],big,ans,v[2510];
void dfs(int cen,int zhong,int cnt,int last){
	if(cen==zhong+1){
		if(cnt>(2*a[last]))ans++,ans=ans%mod;
		return;
	}
	for(int i=last;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(cen+1,zhong,cnt+a[i],i);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
	}
	if(fl){
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			dfs(1,i,0,1);
		}
		cout<<ans;
	}else{
		for(int i=1;i<=(n+1)/2;i++){
			long long a=i,sum=1;
			for(int j=1;j<=i;j++)sum*=a,sum/=j,a--;
			ans=(ans%mod+sum%mod)%mod;
		}
		cout<<ans;
	}
	return 0;
}