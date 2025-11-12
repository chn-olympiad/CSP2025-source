#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	if (x > y)
		return x > y;
	if (x < y)
		return y > x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int numb[10];
	cin >> s;
	for (int i = 0;i <= 6;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			numb[i] = s[i];
	}
	sort(numb + 1,numb + 10 + 1,cmp);
	cout << numb;
	return 0;
 } 
