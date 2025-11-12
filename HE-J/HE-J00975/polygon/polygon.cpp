#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,i;
	cin>>n;
	int a[n];
	while(a[i]!='\n'){
	cin>>a[i];
	i++;
	break;
	}
	
	cout<<n%998;
	return 0;
}
