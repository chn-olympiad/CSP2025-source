#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[50101],k1=0,k2=0,k3=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=a[1]+a[2]+a[3];
	if(n==3){
		if(sum>a[1]*2){
			k1=1;
		}
		if(sum>a[2]*2){
			k2=1;
		}
		if(sum>a[3]*2){
			k3=1;
		}
	}
	if(k1==1&&k2==1&&k3==1) cout<<1;
	else cout<<0;
	return 0;
}
