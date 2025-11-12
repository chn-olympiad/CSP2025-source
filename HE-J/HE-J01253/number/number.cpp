#include<bits/stdc++.h>
using namespace std;
string s;
int t[10]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sl=s.size();
	for(int i=0;i<sl;i++)
	{
		switch(s[i])
		{
			case '1':
				t[1]++;
				break;
			case '2':
				t[2]++;
				break;
			case '3':
				t[3]++;
				break;
			case '4':
				t[4]++;
				break;
			case '5':
				t[5]++;
				break;
			case '6':
				t[6]++;
				break;
			case '7':
				t[7]++;
				break;
			case '8':
				t[8]++;
				break;
			case '9':
				t[9]++;
				break;
			case '0':
				t[0]++;
				break;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(t[i]!=0)
			for(int j=1;j<=t[i];j++)
				cout<<i;
	}
	return 0;
 } 
