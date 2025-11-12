#include<cstdio>
#include<algorithm>
using namespace std;
int a[110] = {0},mz[20][20] = {0};
bool cmp(int,int);
int main()
{
	freopen(&"seat.in"[0],&"r"[0],stdin);
	freopen(&"seat.out"[0],&"w"[0],stdout);
	int m = 0,n = 0;
	scanf(&"%d %d"[0],&n,&m);
	for(int i = 1;i <= n * m;i = i + 1)
	{
		scanf(&"%d"[0],&a[i]);
	}
	int x = a[1];
	bool d = false;
	int i = 0,j = 1;
	std::stable_sort(&a[1],&a[n * m + 1],cmp);
	for(int _ = 1;_ <= n * m;_ = _ + 1)
	{
		int t = a[_];
		if(i == n && d == false)
		{
			j = j + 1;
			d = true;
		}
		else if(i == 1 && d == true)
		{
			j = j + 1;
			d = false;
		}
		else
		{
			if(d == false)
			{
				i = i + 1;
			}
			else
			{
				i = i - 1;
			}
		}
		mz[i][j] = t;
		if(t == x)
		{
			printf(&"%d %d"[0],j,i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
bool cmp(int a,int b)
{
	if(a < b)
	{
		return false;
	}
	return true;
}
