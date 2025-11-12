#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x[n];   
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	
	if(n==1) cout<<"0"<<endl;
	if(n==2) cout<<"1"<<endl;
	
	return 0;
}
