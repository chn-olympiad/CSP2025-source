#include <bits/stdc++.h>
using namespace std;
bool cmp(int y,int z){
	return y>z;
}	
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);	
	int n,m,a[100000];
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m+1,cmp);	
	for(int i=0;i<n*m;i++){
		if(a[0]==a[i]){
			cout<<i;
		}	
	}		
	return 0;
}	
