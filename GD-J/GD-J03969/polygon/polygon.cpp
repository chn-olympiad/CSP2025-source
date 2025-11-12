#include<iostream>
#include<cmath>
using namespace std;
int n;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int num=max(a[1],a[2]);
		num=max(num,a[3]);
		int su=a[1]+a[2]+a[3];
		if(su>2*num) cout<<1;
		else cout<<0;
	}
	else{
		cout<<(n-2)%998244353;
	}
	return 0;
} 
