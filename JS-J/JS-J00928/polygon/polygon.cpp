#include<bits/stdc++.h>
using namespace std;
int a[5005],u[5005],ans;
int n;
void dg(int dep,int l,int sum,int maxn){
	if(dep>n){
			return ;
	}
	if(l>=3&&sum>maxn*2){
		ans++;
		ans%=998244353;
		
		return; 
	}
	for(int i=dep;i<=n;i++){
		if(!u[i])
		{
			u[i]=1;
		dg(dep+1,l+1,sum+a[i],max(maxn,a[i]));
			u[i]=0;
		}
		dg(dep+1,l,sum,maxn);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int maxn=0,sum=0;
		for(int i=1;i<=n;i++){
				maxn=max(maxn,a[i]);
				sum+=a[i];
		}
		if(sum>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	dg(1,0,0,0);
	cout<<ans;
	return 0;
}
