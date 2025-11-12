#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[1000005];
int yu;
int x,y;
int t = 1;
bool ty = 1;

int cmp(const int &a,const int &b)
{
	if (a > b) return 1;
	else return 0;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
		cin >> num[i];
	yu = num[1];
	sort(num + 1,num + n * m + 1,cmp);
	x = 1,y = 1;
	while (1)
	{
		if (x <= 0) 
		{
			x = 1;
			ty = 1;
			y ++;
		}
		if (x >= n + 1)
		{
			x = n;
			ty = 0;
			y ++;
		}
		if (num[t] == yu) break;
		if (ty) x ++;
		else if (!ty) x --;
		t ++;
	}
	cout << y <<  " "<< x << endl;
	return 0;
}
