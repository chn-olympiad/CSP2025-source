#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[105][105];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int z=a[1];
	int x;
	sort(a+0,a+(n*m)+1);
	cout<<z;
	for(int r=1;r<=m;r++){
		if(r%2==1){
			x=1;
			for(int c=x;c<=n;c++){
				b[c][r]=a[c*r];
				if(b[c][r]=z){
					cout<<c<<" "<<r;
					return 0;
				} 
			}
		}else{
			x=n;
			for(int c=x;c>=1;c--){
				b[c][r]=a[c*r];
				if(b[c][r]=z){
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
	}
	return 0;
}
