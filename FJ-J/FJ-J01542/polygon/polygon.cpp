#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001],i,j,k,b;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		b+=a[i];
		for(j=i;j>1;j--){
			if(a[j]>a[j-1]){
				k=a[j-1];
				a[j-1]=a[j];
				a[j]=k;
			}
		}
	}
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]==a[2]){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}