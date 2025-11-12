#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int b[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	if(a==1)
	{
		cout<<s;
	}
	else
	{
		int k=1;
		for(int i=0;i<a;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				b[k]=s[i]-'0';
				k++;
			}
		}
		sort(b,b+k);
		for(int i=k-1;i>0;i--)
		{
			cout<<b[i];
		}
	}
	return 0;
 } 
