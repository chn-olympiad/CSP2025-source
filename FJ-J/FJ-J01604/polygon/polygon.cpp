#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans,h,c,m;
void dfs(int k){
	for(int i=k+1;i<=n;i++){
		h+=a[i];
		c++;
		int u=m;
		m=max(m,a[i]);
		if(c>=3){
			if(h>m*2){
				ans++;
			}
		}
		dfs(i);
		h-=a[i];
		c--;
		m=u;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
	cout<<ans;
	return 0;
}
