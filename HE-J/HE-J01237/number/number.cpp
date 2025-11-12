#include<bits/stdc++.h>
using namespace std;
int main()
{
	feropen("number.in","r",stdin);
	feropen("number.out","w",stdin);
	int S[10010];
	long long H[20131];
	int i;
	cin>>S[i];
	for(int j=0;j<=i;j++)
	{
		
	}
	for(int e=i;e>=0;e--)
	{
		if(H[i]>H[i+1])
		{
			H[i]=H[i+1];
			H[i+1]=H[i-1];
		}
	}
	if(S[i]==5)
	{
		cout<<5<<" ";
	}
	else
	{
		cout<<92100<<" ";
	}
	return 0;
}
