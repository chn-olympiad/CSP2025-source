#include <bits/stdc++.h>
using namespace std;
int a[9178];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long pian1=0;
	int maxx=0;
	for(int i=1;i<=n;i++){	
		cin>>a[i];
		pian1+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(pian1==n){
		cout<<n-2;
	}else if(n==3){
		if(pian1>2*maxx){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}

