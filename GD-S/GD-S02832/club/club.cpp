#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node
{int a, b, c;}mb[N], A[N], B[N], C[N];

bool cmp_a(node n1, node n2)
	{return (n1.a - max(n1.b, n1.c)) > (n2.a - max(n2.b, n2.c));}
bool cmp_b(node n1, node n2)
	{return (n1.b - max(n1.a, n1.c)) > (n2.b - max(n2.a, n2.c));}
bool cmp_c(node n1, node n2)
	{return (n1.c - max(n1.a, n1.b)) > (n2.c - max(n2.a, n2.b));}


int solve()
{
	memset(mb, 0, sizeof mb);
	memset(A, 0, sizeof A); memset(B, 0, sizeof B); memset(C, 0, sizeof C);
	int n; scanf("%d", &n);
	int sum_a = 0, sum_b = 0, sum_c = 0, cnt_a = 0, cnt_b = 0, cnt_c = 0; 
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &mb[i].a, &mb[i].b, &mb[i].c);
		if (mb[i].a > max(mb[i].b, mb[i].c)) cnt_a++;
		if (mb[i].b > max(mb[i].a, mb[i].c)) cnt_b++;
		if (mb[i].c > max(mb[i].a, mb[i].b)) cnt_c++;
	}
	
	memcpy(A, mb, sizeof mb); memcpy(B, mb, sizeof mb); memcpy(C, mb, sizeof mb);
	sort(A + 1, A + n + 1, cmp_a);
	sort(B + 1, B + n + 1, cmp_b);
	sort(C + 1, C + n + 1, cmp_c);
	for (int i = 1; i <= n; i++) sum_a += A[i].a;
	for (int i = 1; i <= n; i++) sum_b += B[i].b;
	for (int i = 1; i <= n; i++) sum_c += C[i].c;
	
	// printf("%d %d %d %d %d %d ", cnt_a, cnt_b, cnt_c, sum_a, sum_b, sum_c);
	if (max(cnt_a, max(cnt_b, cnt_c)) > n/2)
	{
		// printf("sit1 ");
		for (int i = n/2 + 1; i <= n; i++) sum_a -= A[i].a, sum_a += max(A[i].b, A[i].c);
		for (int i = n/2 + 1; i <= n; i++) sum_b -= B[i].b, sum_b += max(B[i].a, B[i].c);
		for (int i = n/2 + 1; i <= n; i++) sum_c -= C[i].c, sum_c += max(C[i].a, C[i].b);
		
		printf("%d\n", max(sum_a, max(sum_b, sum_c)));
	}
	
	else
	{
		// printf("sit2 ");
		for (int i = 1; i <= n; i++) if (A[i].a < max(A[i].b, A[i].c)) 
			sum_a -= A[i].a, sum_a += max(A[i].b, A[i].c);
		for (int i = 1; i <= n; i++) if (A[i].b < max(A[i].a, A[i].c))
			sum_b -= B[i].b, sum_b += max(B[i].a, B[i].c);
		for (int i = 1; i <= n; i++) if (A[i].c < max(A[i].a, A[i].b))
			sum_c -= C[i].c, sum_c += max(C[i].a, C[i].b);
		
		printf("%d\n", max(sum_a, max(sum_b, sum_c)));
	} 
	return 0;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

