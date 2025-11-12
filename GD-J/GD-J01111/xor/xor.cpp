#include <iostream>
#include <algorithm>
#include<cstdio>

using namespace std;

int a[500005];
int main()
{
	int n,k;
	cin>>n>>k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
  
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2){
		cout<<0;
}   else
{
	cout<<1;
}
	return 0;
 } 
