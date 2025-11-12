#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long sum=0;
int cnt=0;
int n;
int a[5005];
void dfs(int suml,int ans,int maxm,int f,int index){
	if(ans>=3){
		if(suml>maxm*2&&f==0){
			sum++;
		}
		if(suml+a[index]>max(a[index],maxm)*2&&f==1){
			sum++;
		}
		sum%=MOD;
	}
	if(index==n)return;
	if(f==1){
		dfs(suml+a[index],ans+1,max(maxm,a[index]),1,index+1);
		dfs(suml+a[index],ans+1,max(maxm,a[index]),0,index+1);
	}
	else {
		dfs(suml,ans,maxm,1,index+1);
		dfs(suml,ans,maxm,0,index+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(cnt==n){
		sum=1;
		for(int i=1;i<=n;i++){
			sum*=2;
			sum%=MOD;
		}
		sum-=(n)%MOD;
		sum%=MOD;
		sum-=((n*(n-1))/2)%MOD;
		sum%=MOD;
		sum-=1;
		cout<<sum;
		return 0;
	}
	dfs(0,0,0,1,1);
	dfs(0,0,0,0,1);
	cout<<sum;
	return 0;
}
