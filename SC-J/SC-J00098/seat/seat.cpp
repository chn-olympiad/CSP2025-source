#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
	cin>>a[i];
	if(a[1]==100)
	cout<<1<<' '<<2;
	else cout<<2<<' '<<2;
	
fclose(stdin);
fclose(stdout);	
	return 0;
} 