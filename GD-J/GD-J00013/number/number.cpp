#include <iostream>
#include <string> 
using namespace std;
int a[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char i:s)
	{
		if(i>='0'&&i<='9')
		{
			a[int(i)]++;
			//cout<<i<<'\n';
		}
	}
	for(char i='9';i>='0';i--)
	{
		for(int j=1;j<=a[int(i)];j++)
		{
			cout<<i;
		}
	} 
	
	return 0;
 } 
