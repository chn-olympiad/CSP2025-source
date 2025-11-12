#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int s=a.size(), w[1000001], r=0;
	for(int i=0;i<s;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			r++;
			w[r]=int(a[i])-48;
		}
			
	}
	sort(w+1, w+r+1);
	for(int i=r;i>0;i--)
		cout << w[i];
	return 0;
}
