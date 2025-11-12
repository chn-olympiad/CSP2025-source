#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp,tot,cnt,ansn,ansm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=n*m;
	for(int i=1;i<=tot;i++) scanf("%d",&a[i]);
	tmp=a[1];
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--)
	{
		cnt++;
		if(a[i]==tmp) break;
	}
	ansm=(cnt-1)/n+1;
	ansn=(cnt-1)%(2*n)+1;
	if(ansn>n) ansn=2*n+1-ansn;
	printf("%d %d",ansm,ansn);
	return 0;
}

