#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],r;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=n*m;
	for(int i=0;i<l;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[0];
	sort(a,a+l);
	for(int i=0;i<=l/2-1;i++)
	{
		swap(a[i],a[l-1-i]);
	}
	int k;
	for(int i=0;i<l;i++)
	{
		if(a[i]==r)
		{
			k=i;
			break;
		}
	}
	k++;
	int hang=k%n,lie=k/n;
	if(k%n!=0) lie++;
	if(k%n==0) hang=n;
	if(lie%2==0) hang=n-hang+1;
	printf("%d %d",lie,hang);
	return 0;
}
