#include<cstdio>
#include<string>
#include<iostream> 
using namespace std;

const int N = 1e4 + 5;
struct node{
	string s1, s2;
}s[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].s1 >> s[i].s2;
	}
	while(q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			printf("0\n");
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			printf("ÈË½ÜµØÁé\n");
		}
	}
	return 0;
}
