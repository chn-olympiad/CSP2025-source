#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],mx,d[1000005];
map<int,int>m;
bool f[100005];
long long ans,sumr;
void dfs(int d){
	if(d>=n+1){
		int mx=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(f[i]){
				mx=max(a[i],mx);
				sum+=a[i];
			}
		} 
		if(sum>2*mx){
			ans++;
		}
		return;
	}
	f[d]=1;
	dfs(d+1);
	f[d]=0;
	dfs(d+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		m[a[i]]++;
		sumr+=a[i];
	}
	if(mx==1){
		long long sum=1;
		while(n--){
			if(n>=1){
				sum=(sum*n)%998244353;
			}
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<ans%998244353;
	}
	
	return 0;
} 
