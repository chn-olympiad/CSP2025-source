#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[5005],n,m;
long long ans;
void dfs(int x,int s,int sum){
	if(a[x]==1&&m==3) return;
	if(s==m){
		if(sum>a[x]){
			ans=(ans+1)%998244353;
			return;
		}
	}
	if(x>=n) return;
	if(s<m){
	    for(int i=x+1;i<=n;i++){ 
		    dfs(i,s+1,sum+a[x]);
        }
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		m=i;
		dfs(0,0,0);
	}
	cout<<ans<<endl;
	return 0;
}
