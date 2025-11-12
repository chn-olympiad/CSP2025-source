#include<bits/stdc++.h>
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const int N=5050,mod=998244353;
ll n,a[N],ans,b[N];
ll dfs(int i,int j,int k){
	if(i<j)return 0;
	if(b[i]-b[i-j]<=k)return 0;
	if(j==1){
		for(int p=1;p<=i;p++){
			if(a[p]>k){
				return i-p+1;
			}
		}
	}else{
		return dfs(i-1,j,k)+dfs(i-1,j-1,k-a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	::std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans+=dfs(j-1,i-1,a[j]);
			ans%=mod;
		}
	
	}cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/
