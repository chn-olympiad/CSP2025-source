#include <bits/stdc++.h>

using namespace std;

string in;
vector<int> number(10,0);

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>in;
	for(int i = 0;i<in.length();i++)
	{
	if(in[i]>='0'&&in[i]<='9')
	{
		number[in[i]-'0']+=1;
	}
	}
	for(int i = 9;i>=0;i--)
	{
		if(number[i]>0)
		{
			for(int j = number[i];j>0;j--) 
			{
				cout<<i;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
