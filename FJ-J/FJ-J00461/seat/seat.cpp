#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,score[105],r,cnt = 1,hang,lie;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++)
	{
		cin >> score[i];
		if(i == 1)
		{
			r = score[i];
		}
	}
	sort(score + 1,score + n * m + 1,cmp);
	while(score[cnt] != r)
	{
		cnt++;
	}
	lie = cnt / n + 1;
	if(lie % 2 == 0)
	{
		if(cnt % n == 0)
		{
			hang = m;
		}
		else
		{
			hang = m - (cnt % n - 1);
		}
	}
	else
	{
		if(cnt % n == 0)
		{
			hang = 1;
		}
		else
		{
			hang = cnt % n;
		}
	}
	/*cout << "-----debug-----" << endl;
	for(int i = 1 ; i <= n * m ; i++)
	{
		cout << score[i] << " ";
	}
	cout << endl << cnt << endl << "-----debug-----" << endl;*/
	cout << lie << " " << hang;
	return 0;
} 

