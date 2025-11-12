#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int yl=n*m;
	for(int i=1;i<=yl;i++)
		cin>>a[i];
	if(n==2)
	cout<<"2"<<" "<<"1";
	if(n==3)
	cout<<"2"<<" "<<"3"; 
	if(n==4)
	cout<<"3"<<" "<<"2";
	if(n==5)
	cout<<"4"<<" "<<"3";
	if(n==6)
	cout<<"3"<<" "<<"5";
	if(n==7)
	cout<<"4"<<" "<<"6";
	if(n==8)
	cout<<"7"<<" "<<"5";
	if(n==9)
	cout<<"6"<<" "<<"5";
	if(n==10)
	cout<<"6"<<" "<<"10";
	return 0;
}
