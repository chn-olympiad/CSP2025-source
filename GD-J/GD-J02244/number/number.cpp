#include<bits/stdc++.h>

using namespace std;

string a;
int num[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> a;
	for(int i=0; i<a.size(); i++) 
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			num[(int)(a[i]-'0')]++;
		}
	} 
	for(int i=9; i>=0; i--)
	{
		for(int j=0; j<num[i]; j++) cout << i;
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
