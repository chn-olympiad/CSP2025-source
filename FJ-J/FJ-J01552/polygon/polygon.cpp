#include<bits/stdc++.h>
using namespace std;
long long a[5005],f[5005],ans=0,n;
void dfs(long long num,long long i,long long c){
	
	if(i>n){
		if(num>0&&c>=3){
		ans=(ans+1)%998244353;
		} 
		return ;
	}	
 	if(a[i]<num||c<=2) dfs(num+a[i],i+1,c+1);	
	dfs(num,i+1,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
} 
