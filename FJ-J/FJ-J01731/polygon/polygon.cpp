#include<bits/stdc++.h>
using namespace std;
long long x=1,k=1,l;
int m,n,xb,mx=-1,lkj,xbo;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		for(int i=3;i<=n;i++){
			for(int j=1;j<=i;j++){
				x*=(n-j-1);
				x%=998244353;
				k*=j;
				k%=998244353;
			}
//			cout<<x/k<<endl;
			l+=x/k;
			l%=998244353;
			x=1;
			k=1;
		}
		cout<<l;
	}
	return 0;
}
/*
*/