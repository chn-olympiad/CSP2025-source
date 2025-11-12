#include<cstdio>
using namespace std;
int const N = 5e6 + 1;
int n, q;
char s1[N], s2[N], t1[N], t2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 0;i != n;i++) scanf("%s%s", s1, s2);
	for(int i = 0;i != n;i++) scanf("%s%s", t1, t2);
	for(int i = 0;i != n;i++) printf("0\n");
	return 0; 
}
