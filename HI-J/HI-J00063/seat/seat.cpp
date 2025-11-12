#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	int num=0,sum=0;
	cin>>x>>y;
	int n=x*y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=a[i-1]){
		num=1;
		sum=1;
	}
	}
	cout<<num<<' '<<sum;
	return 0;
}
