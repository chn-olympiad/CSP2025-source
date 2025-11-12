#include<bits/stdc++.h>
using namespace std;
struct AC
{
	int z;
	int id;
}a[1005];
bool cmp(AC a,AC b)
{
	return a.z>b.z;
}
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].z),a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,r=1,c=1;i<=n*m;i++)
	{
		if(a[i].id==1) printf("%d %d",c,r),exit(0);
		if(c%2==1)
		{
			if(r==n) c++;
			else r++;
		}
		else
		{
			if(r==1) c++;
			else r--;
		}
	}
}
