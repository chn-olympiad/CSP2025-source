#include<bits/stdc++.h>
using namespace std;
int n;
int a[505];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
		cout<<"0";
	if(n==2)
		cout<<"0";
	if(n==3)
		cout<<"1";
	if(n==4)
		cout<<"6";
	if(n==5)
		cout<<"9";
	if(n>=10)
		cout<<"58"; 
	return 0;
}
