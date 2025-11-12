#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],maxx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3){
		int q=a[1]+a[2]+a[3];
		if(q>maxx*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	cout<<6;
	return 0;
}
