#include<bits/stdc++.h>
using namespace std;
long long a[50050],b,c,n,m,ans,sum,ma[50050];
void dfs(long long k,long long mx,int c,int qu){
	if(k>n){
		if(c>mx*2&&qu>=3){
			ans++;ans%=998244353;
			
		}
	}
	else{
		dfs(k+1,mx,c,qu);
		dfs(k+1,max(mx,a[k]),c+a[k],qu+1);
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum=max(sum,a[i]);
	}
	if(sum==1){
		ma[3]=1;int tot=2;
		for(int i=4;i<=n;i++){
			ma[i]=ma[i-1]+tot;sum+=ma[i];tot++;
			ma[i]%=998244353;
			sum%=998244353;
		}
		cout<<sum;
	}
	else{
		dfs(1,-1,0,0);
		cout<<ans;
	}
	return 0;
}



