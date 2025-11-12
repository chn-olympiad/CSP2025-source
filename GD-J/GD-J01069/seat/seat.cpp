#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];
int s[105][105];

void px () {
	for (int i=2;i<=n*m;i++) {
		for (int j=1;j<i;j++) {
			if (a[i]>a[j]) swap(a[i],a[j]);
		}
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n*m;i++) 
		scanf("%d",&a[i]);
	int r=a[1],fl=1,fr=1;
	px();
	bool f=false;
	for (int i=1;i<=n*m;i++) {
		s[fl][fr]=a[i];
		if (fl+1>n && !f) {
			fr++;
			s[fl][fr]=a[++i];
			f=true;
		}
		if (fl-1<1 && f) {
			fr++;
			s[fl][fr]=a[++i];
			f=false;
		}
		if (!f) fl++;
		else fl--;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			if (s[i][j]==r) 
				printf("%d %d",j,i);
	return 0;
}
