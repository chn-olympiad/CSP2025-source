#include <bits/stdc++.h>
using namespace std;
bool book[5005];
int n;
int a[5005];
unsigned long long int ans=0;
void dfs(int x,unsigned long long int sum,int maxn){
	unsigned long long int dsum=sum+a[x];
	int dmaxn=max(a[x],maxn);
	//cout<<x<<" "<<sum<<" "<<maxn<<endl;
	//not choose
	if(x==n){
		if(sum>=3&&sum>maxn*2) ans=ans%998244353+1;
	}
	if(x!=n) dfs(x+1,sum,maxn);
	//choose
	if(x==n){
		if(dsum>=3&&dsum>dmaxn*2) ans=ans%998244353+1;
		return;
	}
	dfs(x+1,dsum,dmaxn);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%998244353<<endl;
	//if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
	//else cout<<0;
	return 0;
} 
