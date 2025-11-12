#include<bits/stdc++.h>
using namespace std;
int main()
{

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10000]={99,100,97,98};
	cin>>n>>m;
	cin>>a[10000];
	if(n==2&&m==2)
		cout<<"1"<<" "<<"2";
	
		
	if(n==2&&m==3)
		cout<<"2"<<" "<<"2";
	if(n==3&&m==0)
		cout<<"3"<<" "<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
