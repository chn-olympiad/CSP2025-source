#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 100;
int t , n , cnt[5];
struct node
{
	int sum , id;
}a[N];
struct Node
{
	int f , s;
}A[5][N];
bool cmp(node x , node y)
{
	return x.sum > y.sum;
}
bool Cmp(Node x , Node y)
{
	return (x.f - x.s) > (y.f - y.s);
}
int flag[N];
signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%lld" , &t);
	while(t --)
	{
		scanf("%lld" , &n);
		int ans = 0;
	//	cout << n << endl;
		for(int i = 1 ; i <= 3 ; i ++)
			cnt[i] = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= 3 ; j ++)
			{
				scanf("%lld" , &a[j].sum);
				a[j].id = j;	
			} 
			sort(a + 1 , a + 3 + 1 , cmp);
			int x = a[1].id;
			A[x][++ cnt[x]].f = a[1].sum , A[x][cnt[x]].s = a[2].sum;
		}	
		sort(A[1] + 1, A[1] + cnt[1] + 1, Cmp);
		sort(A[2] + 1 , A[2] + cnt[2] + 1 , Cmp);
		sort(A[3] + 1 , A[3] + cnt[3] + 1, Cmp);
		for(int i = 1 ; i <= 3 ; i ++)
		{
			for(int j = 1 ; j <= cnt[i] ; j ++)
			{
				if(j <= n / 2)
				{
					ans += A[i][j].f;
//					cout << 1 << ' ' << A[i][j].f << endl;
				}
				else
					ans += A[i][j].s;
//					cout << 2 << ' ' << A[i][j].s << endl;
			}
		}
		printf("%lld\n" , ans);
	} 
	
	return 0;	
} 
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2 
//10 9 8
//4 0 0
