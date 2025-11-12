#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>> s;
	int n = s.size(),m=0;
	for(int i = 0;i<n;i++)
	{
		if(s[i] >='0' && s[i] <='9') 
		{
			m++;
			a[m] = s[i] - '0';
			b[a[m]]++; 
		}
	
	}
	for(int k = 9;k>=0;k--)
	{
		if(b[k]==0) continue;
		for(int j = 1;j<=b[k];j++) cout<<k;
	}

	return 0;
 } 
