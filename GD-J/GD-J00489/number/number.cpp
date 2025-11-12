#include <iostream>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin >> a;
	int b[15];
	for(int i = 0; i<=9; i++) b[i] = 0;
	for(int i = 0; i<a.size(); i++)
	{
		if(a[i] == '0') b[0]++;
		else if(a[i] == '1') b[1]++;
		else if(a[i] == '2') b[2]++;
		else if(a[i] == '3') b[3]++;
		else if(a[i] == '4') b[4]++;
		else if(a[i] == '5') b[5]++;
		else if(a[i] == '6') b[6]++;
		else if(a[i] == '7') b[7]++;
		else if(a[i] == '8') b[8]++;
		else if(a[i] == '9') b[9]++;
	}
	for(int i = 9; i>=0; i--)
	{
		for(int j = 1; j<=b[i]; j++)
		{
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
