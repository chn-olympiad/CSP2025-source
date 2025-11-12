#include<iostream>
using namespace std;
int main()
{
	int t,n,i,m=0;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cin>>n;
		for(int u=1;u<=n;u++)
			cin>>i;
		m+=i;
		cout<<m;
	cout<<endl;
	}
}
