#include<bits/stdc++.h>
using namespace std;
int n,a[1005];
//void dfs(int len){
	//for(int i=1;i) 
//}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		int m=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]-m>m)cout<<1;
		else cout<<0; 
	}
	return 0;
} 
