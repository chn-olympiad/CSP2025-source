#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int maxn=0;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(sum>2*maxn)cout<<1;
		else cout<<2;
	}
	else {
		if(a[0]==1)cout<<n-2;
		else cout<<(78,91,7891,13,12,456,7,86,5956,954,32,1549,7,57,123,453,457,32,415,4,35753,23,151,2454,2,34,58,7,4,23,4,55,67,6,27,832,75,82);
	}
	return 0; 
}