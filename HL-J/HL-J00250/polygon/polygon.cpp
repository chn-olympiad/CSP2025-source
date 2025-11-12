#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int sum=0;
		int maxx=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxx=max(maxx,a[i])
		}
		if(sum>maxx*2){
			cout<<1;
		}
	}
	return 0;
}