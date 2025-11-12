#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 500;
string s1[N], s2[N];
int f[N], ne[N][M];
string tmp;
int n, q;


int main()
{
	freopen("replace.in","r",stdin);
	 freopen("replace.out","w",stdout);
	
	scanf("%d%d", &n, &q);
	for(int k = 1; k <= n; k++)
	{
		cin >> s1[k] >> s2[k];
		ne[k][0] = 0;
		int len = s1[k].size();
		for(int i = 1, j = -1; i < len; i++)
		{
			while(j >= 0 && s1[k][j + 1] != s1[k][i]) j = ne[k][j];
			if(s1[k][i] == s1[k][j + 1]) j++;
			ne[k][i] = j;
		}
	}
	
	
	
	while(q --)
	{
		int ans = 0;
		string t1, t2; 
		cin >> t1 >> t2;
		int len = t1.size();
		for(int h = 1; h <= n; h++)
		{
			int lenn = s1[h].size();
			for(int i = 0, j = -1; i < len; i++)
			{
				while(j >= 0 && (j == lenn || s1[h][j + 1] != t1[i])) j = ne[h][j];
				if(t1[i] == s1[h][j + 1]) j++;
			
				if(j == lenn)
				{
					int l = i - j + 1;
					for(int g = l; g <= i; g++)
						tmp[g] = t1[g], t1[g] = s2[h][g - l];
					if(t1 == t2)  ans ++;
					
					for(int g = l; g <= i; g++)
						t1[g] = tmp[g];
					
				} 
			}
		}	
		
		printf("%d\n", ans);
	}
	
	return 0;	
}
