#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],ans=0,mod=998244353;
void dfs(int cus,int sum,int x,int n){
	if(cus>2&&sum>a[n]){
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<n;i++){
		dfs(cus+1,sum+a[i],i,n);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,0,0,i);
	} 
	cout<<ans;
	fclose(stdin);fclose(stdout);
}
/*20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
