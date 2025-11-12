#include<bits/stdc++.h>
using namespace std;
int n=0,k=0;
int a[100000];
bool flag=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;//n–Ú¡–≥§∂»£¨k 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=0;
		}
	}
	if(flag and n<=2 and k==0) cout<<n/2;
	if(k==0 and flag)
	{
		cout<<n/2;
		
	}

	return 0;
 }       
