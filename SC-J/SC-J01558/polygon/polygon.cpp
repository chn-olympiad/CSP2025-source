#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
void dfs(int step,int sum,int num,int maxn){
	
	if(step==n+1){
		if(num>=3&&sum>maxn*2){
			ans++;
		}
		return ;
	}
	dfs(step+1,sum,num,maxn);
	dfs(step+1,sum+a[step],num+1,a[step]);

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		sort(a+1,a+1+n);
		dfs(1,0,0,0);
		
	}
	else{
		for(int i=3;i<=n;i++){
			long long x=1;
			for(int j=0;j<i;j++){
				x=x*(n-j);
			}
			long long y=1;
			for(int j=1;j<=i;j++){
				y*=j;
			}
			ans+=x/y;
		}
	}
	cout<<ans%998244353;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 