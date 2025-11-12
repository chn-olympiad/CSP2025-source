#include <bits/stdc++.h>
using namespace std;
int n;
int a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		int N=max(max(a[0],a[1]),max(a[1],a[2]));
		if(a[0]+a[1]+a[2]>2*N) cout<<1;
		else cout<<0;
		return 0;
	}//~30pts?
	

	return 0;
}

