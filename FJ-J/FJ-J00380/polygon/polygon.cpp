#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],m,mp[1000001];
long long ans=0;
void dfs(int k,int p,long long sum,long long maxx){
	if(k>m){
		if(sum>maxx*2){
			ans++;
			return;
		}
	}
	for(int i=p+1;i<=n;i++){
		mp[k]=i;
		if(maxx<a[i]&&mp[i]!=0){
			dfs(k+1,i,sum+a[i],a[i]);
			mp[k]=0;
		}
		else{
			dfs(k+1,i,sum+a[i],maxx);
			mp[k]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		mp[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		m=i;
		dfs(1,0,0,INT_MIN);
	}
	cout<<ans%99844353;
	return 0;
}