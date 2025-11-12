#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n==3){
		if(a[0]+a[1]+a[2]>a[0]*2&&a[0]+a[1]+a[2]>a[1]*2&&a[0]+a[1]+a[2]>a[2]*2){
			cout<<1;
		}
	}
	if(n<3){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
