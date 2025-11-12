#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
ULL ans=0;
int n,a[5005];

void dfs(int sum,int ind,int cnt){
	if(cnt>=3 && sum>2*a[ind]) ans++;
	if(ind>=n) return;
	for(int i=ind+1;i<=n;i++){
		dfs(sum+a[i],i,cnt+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	dfs(0,0,0);
	
	cout<<ans%998244353;
	return 0;
} 
