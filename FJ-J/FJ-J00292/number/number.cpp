#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[1000009];
int cnt[19];
char ans[1000009];
int num;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", s+1);
	int n=strlen(s+1);
	
	for (int i=1; i<=n; i++)
		if ('0'<=s[i] && s[i]<='9')
			cnt[s[i]-'0']++;
	
	for (int i=9; i>=0; i--)
		while (cnt[i]--)
//			printf("%d", i); 1e6 TLE
			ans[++num]='0'+i;
	printf("%s\n", ans+1);
	return 0;
}
