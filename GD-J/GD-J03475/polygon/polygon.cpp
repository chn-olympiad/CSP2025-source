#include<bits/stdc++.h>
using namespace std;

long long n,a[1000001],vis[1000001],sum=0;

int dfs(long long k,long long num,long long maxx){
	
	if(k==0){
//		cout<<k<<' '<<num<<' '<<maxx<<' '<<sum<<endl;
		if(num>maxx*2){
			sum+=1;
			sum%=998244353;
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
//			cout<<k<<' '<<num<<' '<<maxx<<' '<<i<<' '<<sum<<endl;
			return dfs(k-1,num+a[i],max(a[i],maxx));
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		dfs(i,0,0);	
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
} 
