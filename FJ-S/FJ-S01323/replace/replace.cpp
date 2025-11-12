#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 1005, L = 2005;
int n, q;
char str1[N][L], str2[N][L], ch1[N], ch2[N]; 
map<pair<string, string>, int> mp; 

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%s%s", str1[i], str2[i]);
	rep(i, 1, n)
	{
		int l = -1, r = -1;
		rep(j, 0, strlen(str1[i]) - 1)
		{
			if(str1[i][j] != str2[i][j] && l == -1) l = j, r = j;
			if(str1[i][j] != str2[i][j]) r = j; 
		}
		if(l == -1 && r == -1) continue;
		char t1[N], t2[N];
		rep(j, 0, r - l)
		{
			t1[j] = str1[i][l + j];
			t2[j] = str2[i][l + j];
		}
		rep(j, 0, r - l)
		{
			str1[i][j] = t1[j];
			str2[i][j] = t2[j];
		}
		str1[i][r - l + 1] = str2[i][r - l + 1] = '\0';
		mp[{str1[i], str2[i]}]++;
	}
	while(q--)
	{
		scanf("%s%s", ch1, ch2);
		int l = -1, r = -1;
		rep(j, 0, strlen(ch1) - 1)
		{
			if(ch1[j] != ch2[j] && l == -1) l = j, r = j;
			if(ch1[j] != ch2[j]) r = j; 
		}
		char t1[N], t2[N];
		rep(j, 0, r - l)
		{
			t1[j] = ch1[l + j];
			t2[j] = ch2[l + j];
		}
		t1[r - l + 1] = t2[r - l + 1] = '\0';
		printf("%d\n", mp[{t1, t2}]);
	}
	return 0;
}
