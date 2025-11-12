#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[5010],b[5010],c[5010],ans,k;
void dfs(int x,int y){
	for(int i=y+1;i<=n;i++){
		if(x>a[i]){
			ans++;
			ans%=998244353;
		}
		dfs(x+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[++k]=a[i]+a[j];
			c[k]=j;			
		}
	}
	for(int i=1;i<=k;i++){
		dfs(b[i],c[i]);
	}
	cout<<ans%998244353;
	return 0;
}
