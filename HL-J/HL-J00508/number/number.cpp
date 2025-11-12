#include<bits/stdc++.h>

using namespace std;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.iout","w",stdout);
	
	
	string a;
	cin>>a;
	int i;
		
	for(i=0;i<=a.size();i++)
	{
		if(char(49)<a[i]<char(57))
		{
			cout<<a[i];
		}
	}
	return 0;
}
