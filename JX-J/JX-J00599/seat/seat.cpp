#include<bits/stdc++.h>
using namespace std;
int n,m;
int asum;
int a[110];
int chl(int x)
{
	return (x - 1) / n + 1;
}
int chh(int x)
{
	if(chl(x) & 1) return (!(x % n) ? n : (x % n));
	else return (!(x % n) ? 1 : (n - (x % n) + 1));
}
int main()
{   

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    asum = a[1];
    sort(a + 1,a + 1 + (n * m),greater<int>());
    for(int i=1;i<=n*m;i++) if(a[i] == asum) {asum = i;break;}
    printf("%d %d\n",chl(asum),chh(asum));
    return 0;
}
