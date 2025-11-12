#include <bits/stdc++.h>
using namespace std;
#define ll int
int n,m,xr,qm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&xr);
	for (int i=1;i<=n*m;i++)
	{
		int a;
		scanf("%d",&a);
		if (a>xr)
			qm++;
	}
	qm++;
	int line=(qm-1)/n+1;
	printf("%d ",line);
	int row=(qm-1)%n+1;
	if (line%2)
		printf("%d",row);
	else
		printf("%d",n-row+1);
	return 0;
	}

