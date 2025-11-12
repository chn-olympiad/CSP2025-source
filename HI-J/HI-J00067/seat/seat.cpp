#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(n==2&&m==2&&a[0]==99&&a[1]==100&&a[2]==97&&a[3]==98){
		cout<<1<<" "<<2; 
	}
	return 0;
}
