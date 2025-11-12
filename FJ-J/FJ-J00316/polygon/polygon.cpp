#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,zj,maxx;
long long ans;
bool cmp(int x,int y){
	return x<y;
}
void dfs(int k,int t,int nn){
	if(k>nn){
		if(sum>2*a[t])
			ans=(ans+1)%998244353;
		return;
	}
	for(int i=t+1;i<=n;i++){
		sum+=a[i];
		dfs(k+1,i,nn);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zj+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		for(int i=3;i<=n;i++){
			long long cheng=1,chu=1;
			for(int j=n,k=1;j>=n-i+1;j--,k++){
				cheng=(cheng*j)%998244353;
				chu=(chu*k)%998244353;
			}
			ans=(ans+(cheng*chu)%998244353)%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<n;i++)
		dfs(1,0,i);
	if(zj>a[n]*2) ans++;
	cout<<ans;
	return 0;
}
