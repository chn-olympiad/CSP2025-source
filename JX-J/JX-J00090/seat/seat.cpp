#include<bits/stdc++.h>
using namespace std;
int cj[105];
int rcj , rpm = 1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m;
	cin >> n >> m;
	int sum = n*m;
	for(int i = 1 ; i <= sum ; i++)
	{
		cin >> cj[i];
		rcj = cj[1];
		if(cj[i] > rcj)
			rpm++;
	}
	int h = 1 , l = 1;
	for(int k = 1 ; k <= sum ; k++)
	{
		if(k == rpm)
		{
			cout << l << " " << h;
			return 0;
		}
		if(l % 2 != 0)
			h++;
		else if(l % 2 == 0)
			h--;
		if(h > n)
		{
			l++;
			h--;
		}
		if(h < 1)
		{
			l++;
			h++;
		}
	}
	return 0;
}
