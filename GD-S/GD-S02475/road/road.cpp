#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int NN = 1e3 + 100;
struct node
{
	int a , b , c;
}M[N] , x[N];
bool cmp(node x , node y)
{
	return x.c < y.c;
}
int n , m , k;
int c[N];
int f[N];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
int dis[NN][NN];
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" ,stdout); 
	scanf("%d%d%d" , &n , &m ,&k);
	for(int i = 1 ; i <= m ; i ++)
	{
		scanf("%d%d%d" , &M[i].a , &M[i].b , &M[i].c);
	}
	if(k == 0)
	{
		sort(M + 1 , M + m + 1 , cmp);
		int sum = 0;
		//cout << 111 << endl;
		for(int i = 1 ; i <= n ; i ++)
		{
			f[i] = i;
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			int x = M[i].a , y = M[i].b , z = M[i].c;
			int xx = find(x) , yy = find(y);
			if(xx != yy)
			{
				f[xx] = yy;
				sum += z; 
			} 
			//cout << i << endl;
		}
		cout << sum << endl;
		return 0;
	}
	else
	{
		sort(M + 1 , M + m + 1 , cmp);
		int sum = 0;
		//cout << 111 << endl;
		for(int i = 1 ; i <= n ; i ++)
		{
			f[i] = i;
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			int x = M[i].a , y = M[i].b , z = M[i].c;
			int xx = find(x) , yy = find(y);
			if(xx != yy)
			{
				f[xx] = yy;
				sum += z; 
			} 
			//cout << i << endl;
		}
		cout << sum << endl;
	}
	return 0;
}
//3 3 0
//1 2 2
//2 3 5
//1 3 3
