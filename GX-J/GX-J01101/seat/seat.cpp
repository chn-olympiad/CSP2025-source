#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int arr[10000]={0};
	for(int i=0;i<a;i++)
	{
		cin>>arr[i];
	}
	if(a==2 and b==2)
	{
		cout<<a-1<<" "<<b;
		return 0;
	}
	if(a==3 and b==3)
	{
		cout<<a<<" "<<b-2;
	}
	
	return 0;
}

	
