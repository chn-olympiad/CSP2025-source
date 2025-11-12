#include<bits/stdc++.h>
using namespace std;
int n,a[5010],g=3;
long long ans=0;
void dfs(int k,int st,int sum){
	if(st>=g-1){
		int * ptr=lower_bound(a+k,a+n,sum);
		ans+=max(int(ptr-a-k),0);
		return;
	}
	for(int i=k;i<=n-g+st;i++)
		dfs(i+1,st+1,sum+a[i]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	if(n==3) 
		if(a[0]+a[1]>a[2])
		{
			cout<<1;
			return 0;
		}
	for(;g<=n;g++){
		dfs(0,0,0);
	}
	cout<<ans%998244353;
	return 0;
}
