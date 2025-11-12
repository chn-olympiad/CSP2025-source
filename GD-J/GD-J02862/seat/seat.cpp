#include<iostream>
using namespace std;

long long n,m;
long long a;
long long x,cnt = 1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	
	cin >> a;
	for(long long i = 2; i <= n * m; i++)
	{
		cin >> x;
		if(x > a) ++cnt;
	} 
	
	if((cnt - 1) / n % 2 == 0) 
	{
		cout << (cnt - 1) / n + 1 << " ";
		if(cnt % n == 0) cnt = n;
		else cnt = cnt % n;
		cout << cnt;
	}
	else
	{
		cout << (cnt - 1) / n + 1 << " ";
		if(cnt % n == 0) cnt = n;
		else cnt = cnt % n;
		cout << n - cnt + 1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
