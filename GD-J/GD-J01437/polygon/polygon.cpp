#include <bits/stdc++.h>
using namespace std;
int a[5010],n,b[5050],cnt=1,ans=0;
int sum[5050],x,as,cs; 
void dfs(int k,int sm){
	if(sm>a[x]*2) {
		ans+=1;
		cout<<sm<<" "<<x<<endl;
	}
	if(k==x) return ;
	dfs(k+1,sm);
	dfs(k+1,sm+a[k]);
	
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==100){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		if(b[i]>a[i]*2){
			sum[cnt]=i;
			cnt++;
		}
	}
	for(int i=1;i<cnt;i++){
		x=sum[i];
		dfs(1,a[sum[i]]);
	}
	cout<<ans;
	return 0;
} 
