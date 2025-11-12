#include<iostream> 
using namespace std;
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string a;
	cin >> a;
	int b[a.length()];
	int o=1;
	for(int i=1;i<=a.length();i++)
	{
		if(a[i]>='1'&&a[i]<='9')
		{
			cin >> b[o];
			o++;
		}
	}
	for(int i=1;i<=a.length();i++)
	{
		for(int i=1;i<=a.length();i++)
		{
			if(b[i]<b[i+1])
			{
				b[i]=b[i+1];
				b[i+1]=b[i];
		}
		cout << b[i] ;
	}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
