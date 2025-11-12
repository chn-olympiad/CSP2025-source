#include<bits/stdc++.h>
using namespace std;
int n,l;long long js;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=3;i<=n;i++){
		long long int q=1,w=1;
		for(int j=1;j<=i;j++){
			q*=j;
		}
		for(int j=n;j>=n-i;j--){
			w*=j;
		}
		js+=(w/q);
	}
	cout<<js;
	return 0;
}

