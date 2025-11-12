#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",.stdin);
	freopen("polygon.out","w",.stdout);
	int n;
	cin>>n;
	int x[n];
	for(int i=0;i<n;i++)
	{
		
		cin>>x[i];
	}
	
	if(n<3) cout<<"0"<<endl;
	if(n==3)
	{
		cout<<"1"<<endl;
	}
	return 0;
}
