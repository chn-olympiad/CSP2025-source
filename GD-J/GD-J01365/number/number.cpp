#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001],b[1000001];
	cin >> a;
	int i = 0,s = 1;
	for(int i = 0;i < 1000001;i++)
	{
		if(a[i] >= '0'&&a[i] <= '9')
	{
	    	b[s] = a[i];
	    	cout << a[i];
	    	s++;
	    	cout << b[s];
	    }
	}
	return 0;
 } 
