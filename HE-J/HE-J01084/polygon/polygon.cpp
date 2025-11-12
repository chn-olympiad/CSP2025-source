#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],w,m;
void q(int i)
{
	if(i>n)return;
	else
	{
		w+=a[i];
		if(w>a[i]*2)m=(m+1)%998244353;
		q(i+1);
		w-=a[i];
		q(i+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	q(1);
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
