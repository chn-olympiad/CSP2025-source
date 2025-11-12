#include <bits/stdc++.h>
using namespace std;
int Num[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt = -1;
	cin >> s;
	for(unsigned i=0; i<s.size(); i++)
	{
		if((s[i]>='0')&& (s[i] <='9'))
		{
			Num[++cnt] = (s[i] - '0');
		}
	}
	
	for(int i=0; i<cnt; i++)
		for(int j=i+1; j<=cnt; j++)
		{
			if(Num[j]>Num[i])
				swap(Num[i], Num[j]);
		}
		
	for(int i=0; i<=cnt; i++)
		cout << Num[i];
	cout << endl;
	return 0;
}
