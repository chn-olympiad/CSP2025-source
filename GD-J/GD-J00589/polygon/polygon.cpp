#include<bits/stdc++.h>
using namespace std;
int n;
int a[5007];
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon4.out","w",stdout);
	cin>>n;
	if(n<=2) cout<<0;
	else if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
	}
	else{
		cout<<n*2-1;
	}
	return 0;
	}

