#include <bits/stdc++.h>
using namespace std;
struct s;
int a[10005];
int main()
{
	//freopen("number.in","w",stdin)
	//freopen("number.out","r",stdout)
	cin >> s;
	scanf("%lld",&s);
	for (int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i] == '9')
		{
			sort(s[i]);
			cout << i << endl;
		}
		
	}
	//fclose("number.in")
	//fclose("munber.out")
	return 0;
}
