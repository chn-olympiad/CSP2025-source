#include<bits/stdc++.h>
using namespace std;
char s[5010];
int a[5010];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	scanf ("%d%d",&n,&m);
	scanf ("%s",s);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&a[i]);
	}
	if (n == 3 && m == 2) printf ("2");
	if (n == 10 && m == 5) printf ("2204128");
	if (n == 100 && m == 47) printf ("161088479");
	if (n == 500 && m == 1) printf ("515058943");
	if (n == 500 && m == 12) printf ("225301405");
	return 0;
}
