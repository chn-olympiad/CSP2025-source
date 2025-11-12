#include<bits/stdc++.h>
using namespace std;
#define N 1000005
char x[N],cch[N];
long long hl; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<1000000;i++)
	{
		cin>>x[i];
		

		if(x[i])
		{	
				hl++;
				cch[i]=x[i];

				cout<<cch[i];
	
		}
	}
	
	return 0;
}
