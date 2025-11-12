#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int summ=a[1]+a[2]+a[3];
		int maxx=max({a[1],a[2],a[3]});
		if(summ>2*maxx) cout<<1;
		else cout<<0;
	}
	return 0;
}