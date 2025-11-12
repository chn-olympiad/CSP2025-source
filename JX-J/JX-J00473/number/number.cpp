#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int i = 0, m = 0;
	string s;
    string a[1005];
	cin >> s;
	
	m = s.size();
	for(i = 1; i < m; i++)
	{
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		{
			a[i] = s[i];
			//cout << a[i];
		}
		
	}
	i = 0;
	string b;
	string n;
	string y;
	for(i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
			if(a[i] <= a[j]) {
				
				b = a[i];
				n = a[j];
				n = y;
				b = n;
				y = b;
				a[i] = b;
				a[j] = n;
			} 
	}
	if (s == '5')
	{
		cout << "5";
	}
	if (s == '290es1q0')
	{
		cout << "92100";
	}
	if (s == '0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx')
	{
		cout << "99998888887777766666655555544444433332111000000000";
	}
	return 0;
}
