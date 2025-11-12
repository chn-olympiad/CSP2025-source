#include<iostream>
#include<algorithm>
using namespace std;
int n,m,lin,col,tmp,rk;
struct stu{
	int src,id;
	bool operator < (const stu s) const
	{return src > s.src;}
};
stu s[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> s[i].src,
		s[i].id = i;
	tmp = s[1].src;
	sort(s + 1,s + n * m + 1);
	for(int i = 1;i <= n * m;i++)
	{
		if(s[i].id == 1)
		{
			rk = i;
			break;
		}
	}
	col = (rk + n - 1) / n;
	if(col & 1)
	{
		lin = rk - (col - 1) * n;
		cout << col << ' ' << lin;
	}
	else
	{
		lin = (n + 1 - (rk - (col - 1) * n));
		cout << col << ' ' << lin;
	}
	return 0;
}
