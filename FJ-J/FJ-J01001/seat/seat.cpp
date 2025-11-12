#include<iostream>
using namespace std;
int main(){
	freoper("seat.in","r",stdin);
	freoper("seat.out","w",stdout);
	int n,m,s=1;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) s++;
	}
	
	if(s/m%2==1) cout<<s/m<<" "<<s%m+2;
	else cout<<s/m<<" "<<m-s%m-2;
	return 0;
}
