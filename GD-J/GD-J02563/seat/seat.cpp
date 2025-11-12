#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=0;
	int first=0;
	int pos=1;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1)first=a;
		else if(a>first)pos++;
	}
	int x=0,y=0;
	if(pos%n==0)x=pos/n;
	else x=pos/n+1;
	if(x%2==1){
		if(pos%n==0)y=n;
		else y=pos%n;
	}
	else{
		if(pos%n==0)y=1;
		else y=n-(pos%n)+1;
	}
	cout<<x<<" "<<y; 
	return 0;
}
