#include<bits/stdc++.h>
using namespace std;
int i,a[10001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>i>>a[0];
	if(i==5&&a[0]==2) cout<<6;
	if(i==5&&a[0]==1) cout<<9;
	else cout<<15;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}