#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int k=a[1];

	sort(a+1,a+1+n*m,greater<int>());
	int p=0;
	for(int i=1;i<=n*m;i++) if(a[i]==k) p=i;

	int h,l=ceil(p*1.0/n);
	if(l%2==0) h=1+(l*n-p);
	else h=n-(l*n-p);
	printf("%d %d\n",l,h);
	
	fclose(stdin); fclose(stdout);
	return 0;
}
