#include<bits/stdc++.h>
using namespace std;
int n,m,d,k,w;
int main()
{
	cin>>m>>m>>d>>k>>w;
	for(int i=1;i<=1;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i<=m&&j<=k)
			{
				w=j*i;
				cout<<i<<endl;
				cout<<j<<endl;
			}else{
				break;
			}	
		}
	}
	return 0;
}
