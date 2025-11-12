#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int b[1005];
int a[1005];
struct node{
	int ma,s,as;
}ans[1005];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int maxx;
	for(int i=1;i<=n;i++){
		maxx=max(a[i],maxx);
		m+=a[i];
	}
	if(m>maxx*2) cout<<1;
	else cout<<0;
	return 0;
} 
