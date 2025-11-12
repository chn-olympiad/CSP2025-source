#include <cstdio>
#include <cstring>
using namespace std;

char S[1000005];
int a[100];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", S);
	int l = strlen(S);
	for (int i = 0; i < l; i++)
		if (S[i] >= 48 && S[i] <= 57)
			a[S[i] - 48]++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++)
			printf("%d", i);
	return 0;
}
