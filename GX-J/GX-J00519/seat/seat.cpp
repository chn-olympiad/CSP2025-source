#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	int b=a[1];
	for(int i=0;i<n*m;i++){
		for(int j=0;i<n*m;j++){
			if(a[i]<a[j])
				swap(a[i[,a[j]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			c=m/i;
			r=n/m;
			cout<<c<<m
		}
	}
	return 0;
}
