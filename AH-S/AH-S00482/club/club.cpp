#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5 + 5;
struct node
{
	ll a , b , c;
	ll mx;
	ll ida , idb , idc;
	ll go_where;
	ll val;
};
node s[M];
bool vis[M];
ll n;
bool cmp1(node x , node y)
{
	return x.a > y.a;
}
bool cmp2(node x , node y)
{
	return x.b > y.b;
}
bool cmp3(node x , node y)
{
	return x.c > y.c;
}
bool cmpA(node x , node y)
{
	return x.ida < y.ida;
}
bool cmpB(node x , node y)
{
	return x.idb < y.idb;
}
bool cmpC(node x , node y)
{
	return x.idc < y.idc;
}
bool cmp(node x , node y)
{
	if(x.a == y.a)
	{
		if(x.b == y.b)
		{
			if(x.c == y.c)
				return x.mx > y.mx;
			return x.c > y.c;
		}
		return x.b > y.b;
	}
	return x.a > y.a;
}
bool cmpsum(node x , node y)
{
	return x.val < y.val;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ll T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		vector<node> A;
		vector<node> B;
		vector<node> C;
		for(ll i = 1 ; i <= n ; i++)
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
			s[i].mx = max(s[i].a , max(s[i].b , s[i].c));
		}
		sort(s + 1 , s + n + 1 , cmp);
		ll ans = 0;
		for(ll i = 1 ; i <= n ; i++)
		{
			if(s[i].a == s[i].mx && vis[i] == 0)
				A.push_back(s[i]) , ans += s[i].a;
			else if(s[i].b == s[i].mx && vis[i] == 0)
				B.push_back(s[i]) , ans += s[i].b;
			else if(s[i].c == s[i].mx && vis[i] == 0)
				C.push_back(s[i]) , ans += s[i].c;
		}
		sort(A.begin() , A.end() , cmpA);
		sort(B.begin() , B.end() , cmpB);
		sort(C.begin() , C.end() , cmpC);
		ll sizea = A.size() , sizeb = B.size() , sizec = C.size();
		if(sizea > n / 2)
		{
			for(ll i = 0 ; i < sizea ; i++)
			{
				if(A[i].b > A[i].c)
				{
					A[i].go_where = 2;
					A[i].val = A[i].a - A[i].b;
				}
				else
				{
					A[i].go_where = 3;
					A[i].val = A[i].a - A[i].c;
				}
			}
			sort(A.begin() , A.end() , cmpsum);
			for(ll i = 0 ; i < sizea - n / 2 ; i++)
			{
				if(A[i].go_where == 2)
				{
					B.push_back(A[i]);
					ans = ans - A[i].a + A[i].b;
				}
				else
				{
					C.push_back(A[i]);
					ans = ans - A[i].a + A[i].c;
				}
			}
		}
		else if(sizeb > n / 2)
		{
			for(ll i = 0 ; i < sizeb ; i++)
			{
				if(B[i].a > B[i].c)
				{
					B[i].go_where = 1;
					B[i].val = B[i].b - B[i].a;
				}
				else
				{
					B[i].go_where = 3;
					B[i].val = B[i].b - B[i].c;
				}
			}
			sort(B.begin() , B.end() , cmpsum);
			for(ll i = 0 ; i < sizeb - n / 2 ; i++)
			{
				if(B[i].go_where == 1)
				{
					A.push_back(B[i]);
					ans = ans - B[i].b + B[i].a;
				}
				else
				{
					C.push_back(B[i]);
					ans = ans - B[i].b + B[i].c;
				}
			}
		}	
		else if(sizec > n / 2)
		{
			for(ll i = 0 ; i < sizec ; i++)
			{
				if(C[i].b > C[i].a)
				{
					C[i].go_where = 2;
					C[i].val = C[i].c - C[i].b;
				}
				else
				{
					C[i].go_where = 1;
					C[i].val = C[i].c - C[i].a;
				}
			}
			sort(C.begin() , C.end() , cmpsum);
			for(ll i = 0 ; i < sizec - n / 2 ; i++)
			{
				if(C[i].go_where == 2)
				{
					C.push_back(C[i]);
					ans = ans - C[i].c + C[i].b;
				}
				else
				{
					C.push_back(A[i]);
					ans = ans - C[i].c + C[i].a;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
