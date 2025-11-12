#include<bits/stdc++.h>
using namespace std;
const int N=110;

int n, m, R, r;
int a[N];

bool cmp(const int &a, const int &b)
{
	return a> b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n*m;i++)
		scanf("%d", a+i);
	R = a[1];
	sort(a+1, a+n*m+1, cmp);
	int cl=1, rw=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R){
			printf("%d %d", cl, rw);
			return 0;
		}
		if(rw==n&&cl%2==1){
			cl++;
		}
		else if(rw==1&&cl%2==0){
			cl++;
		}
		else if(cl%2==1){
			rw++;
		}
		else rw--;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
