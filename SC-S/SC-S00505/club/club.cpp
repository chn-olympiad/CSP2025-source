#include <bits/stdc++.h>
using namespace std;
long long t,n,sum;
struct Tclub
{
	int a,b,c;
} p[1000005];
int cse(Tclub x)
{
	long long d1 = 0,d2 = 0,d3 = 0;
	long long suma = 0,sumb = 0,sumc = 0;
	long long q = n / 2;
	if ((d1 < q) && (d2 < q) && (d3 < q)){
		if (x.a == x.b && x.a == x.c) {
			if (d1 <= d2 && d1 <= d3) d1++,suma += x.a;
			else if (d2 <= d1 && d2 <= d3) d2++,sumb += x.b;
			else if (d3 <= d1 && d3 <= d2) d3++,sumc += x.c;
		}
		else if (x.a > x.b && x.a > x.c) d1++,suma += x.a;
		else if (x.b > x.a && x.b > x.c) d2++,sumb += x.b;
		else if (x.c > x.a && x.c > x.b) d3++,sumc += x.c;
	}
	else if ((d1 == q) && (d2 < q) && (d3 < q)){
		if (x.b == x.c) {
			if (d2 <= d3) d2++,sumb += x.b;
			else if (d3 <= d2) d3++,sumc += x.c;
			else if (x.b > x.c) d2++,sumb += x.b;
			else if (x.c > x.b) d3++,sumc += x.a;
		}
	}
	else if ((d2 == q) && (d1 < q) && (d3 < q)){
		if (x.a == x.c) {
			if (d1 <= d3) d1++,suma += x.a;
			else if (d3 <= d1) d3++,sumc += x.c;
			else if (x.a > x.c) d1++,suma += x.a;
			else if (x.c > x.a) d3++,sumc += x.c;
		}
	}
	else if ((d3 == q) && (d1 < q) && (d2 < q)){
		if (x.a == x.c) {
			if (d1 <= d2) d1++,suma += x.a;
			else if (d2 <= d1) d2++,sumb += x.b;
			else if (x.a > x.b) d1++,suma += x.a;
			else if (x.b > x.a) d2++,sumb += x.b;
		}
	}
	else if ((d1 == q) && (d2 == q) && (d3 < q)) d3++,sumc += x.c;
	else if ((d1 < q) && (d2 == q) && (d3 == q)) d1++,suma += x.a;
	else if ((d1 == q) && (d2 < q) && (d3 == q)) d2++,sumb += x.b;
	long long ucesum = suma+sumb+sumc;
	return ucesum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for (int i = 1;i <= t;i++){
		sum = 0;
		scanf("%lld",&n);
		for (int j = 1;j <= n;j++){
			scanf("%lld %lld %lld",&p[i].a,&p[i].b,&p[i].c);
			sum += cse(p[i]);
		}
		printf("%lld\n",sum);
	}
	return 0;
}