#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N],tmp,idx;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==tmp)
			idx=i;
	}
	int tmp2=idx/n,tmp3=idx%n;
	if(idx%n!=0)
		tmp2++;
	if(tmp3==0) tmp3=n;
	if(tmp2%2==0) tmp3=n-tmp3+1;
	printf("%d %d",tmp2,tmp3);
	return 0;
}
