#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	int sumi=0,maxxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sumi+=a[i];
		maxxx=max(maxxx,a[i]);
	}
	if(maxxx*2<sumi)cout<<1;
	else cout<<0;
	return 0;
} 
