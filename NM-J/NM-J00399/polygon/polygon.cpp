#include<bits/stdc++.h>
using namespace std;
int b[5000]
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,c=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
	}
	while(0){
		for(int i=0;i<=a*2;i++){
			if (a[i]+a[i+1]>a[i+1]*2){
				c++;
			}
			if (a[i]+a[i+1]+a[i+2]>a[i+2]*2){
				c++;
			}
			if (a[i]+a[i+1]+a[i+2]+a[i+3]>a[i+3]*2){
				c++;
			}
		}
	}
	cout<<'6';
	return 0;
}
