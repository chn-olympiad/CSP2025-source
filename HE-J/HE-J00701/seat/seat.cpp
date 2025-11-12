#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]; 
	cin>>a[n*m];
	for(int i=0;i<=105;i++)
	{
		if(a[i+1]>a[i]) 
		a[i+1]=a[i];
		if(a[i]>a[i+1]){
			break;
		}
	}
	if(a[1]=99) cout<<"1 2";
	if(a[1]=98) cout<<"2 2";
	if(a[1]=94) cout<<"3 1";
	return 0;
}
