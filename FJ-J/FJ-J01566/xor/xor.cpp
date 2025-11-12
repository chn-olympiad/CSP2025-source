#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[1000000],n,k,x,y=0;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		x=a[i];
		for(int j=i+1;j<i+k-1;j++){
			x=x^a[j];
		}
		if(x>=y){
			y=x;
		}
	}
	cout<<y;
}
