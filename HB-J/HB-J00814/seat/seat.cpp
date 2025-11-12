#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	int a[100],b,c;
	int sum=1;
	cin>>b;
	a[1]=b;
	for(int i=2;i<x*y;i++){
		cin>>a[i];
	}
	for(int i=1;i<x*y;i++){
		for(int j=1;j<i;j++){
			if(a[j]<a[i]){
				c = a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	}
	for(int i=1;i<x*y;i++){
		if(a[i]==b and sum%2==1){
			cout<<(i-1)%y+1<<sum;
		}
		else{
			if(a[i]==b and sum%2==0){
				cout<<abs(((i+y)%y)-y)<<sum;
			}
		}
		if(i>y){
			sum = i/y;
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}

