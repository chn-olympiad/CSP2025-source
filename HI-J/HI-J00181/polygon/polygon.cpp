#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N],ans;
bool xx[N];
void dfs(int x,int t,int mx){
	ans%=998244353;
	if(x>mx*2)ans++;
	if(t==n)return;
	for(int i=t+1;i<=n;i++){
		dfs(x+a[i],i,max(mx,a[i]));
	}	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	bool s1m=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&!xx[a[i]])s1m=false;
		else xx[a[i]]=true;
		sum+=a[i]; 
	}
	if(s1m){
		for(int i=n;i>=3;i--){
			int s1=1,s2=1;
			for(int j=n;j>=n-i+1;j--)s1*=j;
			for(int j=i;j>=1;j--)s2*=j;
			ans+=(s1/s2)%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
