#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[100005];
map<int,int>mp;
int t[15][15],p;
bool cmp (int a,int b) {
	return a > b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n * m; i++) scanf("%d",&a[i]);
	mp[a[1]] = 1;
	sort (a + 1,a + n * m + 1,cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1)
			for (int j = 1; j <= n; j++)
				t[i][j] = a[++p];
		else
			for (int j = n; j >= 1; j--)
				t[i][j] = a[++p];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[t[i][j]]) {
				printf("%d %d\n",i,j);
				return 0;
			}
	return 0;
}
