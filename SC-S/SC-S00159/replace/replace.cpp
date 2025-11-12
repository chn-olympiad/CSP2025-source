#include <bits/stdc++.h>

using namespace std ;

inline int read()
{
	int x = 0 , f = 1 ; char ch = 0 ;
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1 ; ch = getchar() ;}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

const int N = 2e5 + 10 ;

string a[N] , b[N] ;
int n , q , vis[N] , st[26][26] , s1[N] , s2[N] , ne[N];
vector<int> vec[26][26] ;

signed main()
{
	freopen("replace.in" , "r" , stdin) ;
	freopen("replace.out" , "w" , stdout) ;
	n = read() , q = read() ;
	for(int i = 1 ; i <= n ; i ++ ) cin >> a[i] >> b[i] ;
	for(int i = 1 ; i <= n ; i ++ )
	{
		for(int j = 0 ; j < 26 ; j ++ ) for(int k = 0 ; k < 26 ; k ++ ) st[j][k] = 0 ;
		for(int j = 0 ; j < a[i].size() ; j ++ )
		{
			if(a[i][j] != b[i][j] && !st[a[i][j] - 'a'][b[i][j] - 'a']) vec[a[i][j] - 'a'][b[i][j] - 'a'].push_back(i) , st[a[i][j] - 'a'][b[i][j] - 'a'] = true ;
		}
	}
	while(q -- )
	{
		string x , y ;
		cin >> x >> y ;
		for(int i = 1 ; i <= n ; i ++ ) vis[i] = 0 ;
		int cnt = 0 ;
		int l = 0 , r = 0 ;
		for(int i = 0 ; i < x.size() ; i ++ )
		{
			if(x[i] != y[i]) 
			{
				r = i ;
				if(!l) l = i ;
				for(int j = 0 ; j < vec[x[i] - 'a'][y[i] - 'a'].size() ; j ++ ) vis[vec[x[i] - 'a'][y[i] - 'a'][j]] ++ ;
				cnt ++ ;
			}
		}
		int cnt1 = 0 , cnt2 = 0 , ans = 0 ;
		for(int i = 1 ; i <= n ; i ++ )
		{
			if(vis[i] < cnt) continue ;
			if(a[i].size() > x.size()) continue ;
			if(b[i].size() > y.size()) continue ;
			for(int j = 0 ; j <= l && x.size() - j > a[i].size() ; j ++ )
			{
				if(j + a[i].size() <= r ) continue ;
				int k = 0 , lp = j ;
				while(a[i][k] == x[lp] && k < a[i].size() ) k ++ , lp ++ ;
				if(k == a[i].size()) s1[++cnt1] = j ;
			}
			for(int j = 0 ; j <= l && y.size() - j > b[i].size() ; j ++ )
			{
				if(j + b[i].size() <= r) continue ;
				int k = 0 , lp = j ;
				while(b[i][k] == y[lp] && k < b[i].size() ) k ++ , lp ++ ;
				if(k == b[i].size()) s2[++cnt2] = j ;
			}
//			for(int j = 1 ; j <= cnt1 ; j ++ ) cout << s1[j] << endl ;
			for(int j = 1 , k = 1 ; j <= cnt1 && k <= cnt2 ; )
			{
				if(s1[j] < s2[k]) j ++ ;
				else if(s1[j] > s2[k]) k ++ ;
				else ans ++ , j ++ , k ++ ;
			}
		}
		printf("%d\n" , ans) ;
	}
	return 0 ;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/