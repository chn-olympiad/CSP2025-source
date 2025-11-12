#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

char s[N];
int n, t[20];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", s+1), n=strlen(s+1);
	for (int i=1; i<=n; i++) if (s[i]>='0' && s[i]<='9') t[s[i]-'0']++;
	for (int i=9; i>=0; i--) for (int j=1; j<=t[i]; j++) printf("%d", i);
	
	return 0;
} 
