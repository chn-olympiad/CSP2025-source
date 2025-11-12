#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n , m , a , it;
vector<int> v;
bool cmp(int a , int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf("%d %d" , &n , &m);
	int tmp;
	for (int i = 0;i < n * m;i++)
	{
		scanf("%d" , &tmp);
		v.push_back(tmp);
		if (i == 0)
			a = tmp;
	}
	sort(v.begin() , v.end() , cmp);
	for (int i = 0;i < v.size();i++)
	{
		if (v[i] == a)
		{
			it = i;
			break;
		}
	}
	it += 1;
	int h , l;
	l = it / n;
	if (it % n)
		l++;
	it %= n;
	if (l % 2)
		h = (it == 0 ? n : it);
	else
		h = (it == 0 ? 1 : n - it + 1);
	printf("%d %d\n" , l , h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}