#include<bits/stdc++.h>
using namespace std;
int main()
{
	fropen("number.in","r",stdin);
	fropen("number.out","w",stdout);
	int s;
	cin>>s;
	if(s>=1)
	{
		s=s-1;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
}
