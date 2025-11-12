#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],R;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int k=0,c=1,r=1;
	while(a[k]==R){
		c++;
		if(c>n){
			r++;
			c=1;
		}
		k++;
	}
	cout<<c<<" "<<r+1;
	return 0;
}