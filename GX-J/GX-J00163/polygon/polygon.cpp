#include<bits/stdc++.h>
using namespace std;
int a[5011];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0,maxx=-1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		num+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(num>2*maxx){
			cout<<1;return 0;
		}
		else{
			cout<<0;return 0;
		}
	}
	return 0;
}
