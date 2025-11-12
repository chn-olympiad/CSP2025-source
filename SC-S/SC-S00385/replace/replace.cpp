#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x;
}

const int MAXN = 5e6 + 5;

int n , q;

unsigned long long get_hash(char *s , int l , int r)
{
	unsigned long long res = 0;
	for(int i = l;i <= r;i++)
	{
		res = res * 131 + s[i] - 'a' + 1;
	}
	return res;
}

unsigned long long hash1[MAXN];

unsigned long long hash2[MAXN];

char s1[MAXN] , s2[MAXN];

int ans;

int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	
	n = read();
	q = read();
	
	for(int i = 1;i <= n;i++)
	{
		scanf("%s" , s1);
		scanf("%s" , s2);
		
//		cout << i << endl;
//		cout << s1 << " " << s2 << endl;
		
		hash1[i] = get_hash(s1 , 0 , strlen(s1) - 1);
		hash2[i] = get_hash(s2 , 0 , strlen(s2) - 1);
	}
	
//	int num = 0;
	
	while(q--)
	{
		scanf("%s" , s1);
		scanf("%s" , s2);
		
//		cout << i << endl;
//		num++;
//		cout << num << endl;
//		cout << s1 << " " << s2 << endl;
		
		int len = strlen(s1);
		
		int ans = 0;
		
		int l , r;
		
//		int ol = 0;
		
		for(int i = 0;i < len;i++)
		{
			if(s1[i] != s2[i])
			{
				l = i;
				break;
			}
		}
		
		for(int i = len - 1;i >= 0;i--)
		{
			if(s1[i] != s2[i])
			{
				r = i;
				break;
			}
		}
		
//		num++;
//		
//		cout << num << endl;
		
//		if(ol)
//		{
//			printf("0\n");
//			continue;
//		}
		
		for(int i = r - l + 1;i <= len;i++)
		{
			for(int L = max(l - (i - (r - l + 1)) , 0);L <= l;L++)
			{
				int R = L + i - 1;
				
				if(R >= len)break;
				
//				cout << L << " " << R << endl;
			
				unsigned long long hsh1 = get_hash(s1 , L , R);
				unsigned long long hsh2 = get_hash(s2 , L , R);
				
				for(int k = 1;k <= n;k++)
				{
					if(hash1[k] == hsh1 && hash2[k] == hsh2)ans++;
				}
			}
		}
		
		printf("%d\n" , ans);
	}
	
	return 0;
}

/*

in:

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

out:

2
0

*/