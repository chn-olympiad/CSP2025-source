#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5001];
	int u=3;
	a[0]=0; 
	int e=0;
	if(n==3){
		e=1;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(e){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<'1';
		}
	} 
	return 0;
}
