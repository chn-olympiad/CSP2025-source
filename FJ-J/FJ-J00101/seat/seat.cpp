#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],p=0,o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b[n*m]={};
	for(int i=0;i<(n*m);i++){
		cin>>b[i];
		if(i==0){
			o=b[i];
		}
		p=b[i];
		for(int j=0;j<i;j++){
			if(b[i]>b[j]){
				for(int k=i;k>=j;k--){
					b[k]=b[k-1];
				}
				b[j]=p;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==o){
			o=i+1;
			break;
		}
	}
	int x,y;
	x=o/n;
	if(x*n<o){
		x++;
	}
	y=o%n;
	if(o%n==0){
		y=o;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
