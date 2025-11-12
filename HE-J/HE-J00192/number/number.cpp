#include<bits/stdc++.h>
using namespace std;	
char S[1000000];
int A[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(S,'A',sizeof(S));
	memset(A,10,sizeof(A));
	int t=0;
	cin>>S;
	for(int i=0;i<1000000;i++)
	{
		if(S[i] != 'A')
		{
			if(S[i]-'0'>=0 && S[i]-'0'<=9)
			{
				A[t]=S[i]-'0';
				t++;
			}
		}
	}
	sort(A,A+t);
	for(int i=t-1;i>=0;i--)
	{
		cout<<A[i];
	}
	return 0;
}
