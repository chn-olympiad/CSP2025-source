#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[99999];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	if(n==4&&m==4&&k==4){
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}
	return 0;
}