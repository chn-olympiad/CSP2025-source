#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	cin>>n;
	int A[n],B[n],c[n];
	int sum_A=0,sum_B=0,sum_C=0;
	for(int i=0;i<n;i++)
	{
		cin>>A[i]>>B[i]>>C[i];
	}
	for(int i=0;i<n;i++)
	{
		
		if(A[i]==max(A[i],max(B[i].C[i])))
		{
			a++;
			sum_A+=A[i];
		}
		if(B[i]==max(A[i],max(B[i].C[i])))
		{
			b++;
			sum_B+=B[i];
		}
		if(C[i]==max(A[i],max(B[i].C[i])))
		{
			c++;
			sum_B+=B[i];
		}
		while(a>n/2 || b>n/2 || c>n/2)
		{
			if(a>n/2)
		{
			a--;
			b++;
			sum_A-=A[i];
		}
		if(b>n/2)
		{
			b--;
			c++;
			sum_B-=B[i];
		}
		if(c>n/2)
		{
			c--;
			a++;
			sum_C-=C[i];
		}
		}
	}
	cout<<sum_A<<endl;
	cout<<sum_B<<endl;
	cout<<sum_C<<endl;
 	return 0;
}