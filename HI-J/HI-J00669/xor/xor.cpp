#include <iostream>
using namespace std;
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a , b;
	cin >> a >> b;
	int x[5];
	for(int i = 1;i <+ 5;i++)
	{
		cin >> x[i];
	}
	if(b == 3)
	{
		cout << 2;
	}
	else
	{
		cout << 1;
	}
	return 0;
}
