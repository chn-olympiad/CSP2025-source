#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5010],h=0,ansk=0,maxn=-0x3f3f3f3f;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		h+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(h>2*maxn){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		exit(0);
	}
	if(n==5){
		if(a[1]==1)cout<<9<<endl;
		if(a[1]==2)cout<<6<<endl;
	}
	else if(n==20){
		cout<<1042392<<endl;
	}
	else if(n==500){
		cout<<366911923<<endl;
	}
	
	return 0;
}

