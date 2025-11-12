#include <bits/stdc++.h>
using namespace std;
const int N= 998244353;
int a[5005],n,ans=0;
void dfs(int x,int sum,int shu){
	//if(x>n) return ;
	if(shu>=3){ 
		//cout<<a[x-1]<<" ";
		if(sum>a[x]*2) ans++;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+=a[i],shu++);
	}
	return ;
}
 
int main() {
	freopen("polygon.in","r","stdin");
	freopen ("polygon.out","w","stdout");
	 cin>>n;
	for(int i=1; i<=n; i++) {
		 cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans%N;
	return 0;
}

