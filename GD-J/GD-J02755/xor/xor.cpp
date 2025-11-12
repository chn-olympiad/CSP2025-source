#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
map<int , int> num;
int n , k , ans , lst;
int a[N] , b[N];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d" , &a[i]);
		b[i] = a[i] ^ b[i - 1];
	}
//	for(int i = 1 ; i <= n ; i ++)
//		cout << a[i] << ' ';
//	cout << endl;
	for(int i = 1 ; i <= n ; i ++)
	{
		num[b[i - 1]] ++;
		if(a[i] == k)
		{
			ans ++;
			//cout << i << endl;
			num.clear();
			continue;
		}
		int x = k ^ b[i];
//		cout << x << ' ' ;
		if(num[x])
		{
			ans ++;
			lst = i;
			num.clear();
//			cout << i << endl;
		}	
	}
	printf("%d" , ans);
	return 0;
}

