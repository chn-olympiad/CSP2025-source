#include<bits/stdc++.h>
using namespace std;
int n,m,R,Ri,ansm,ansn;
int f[105];
bool cmp(int x,int y)
{
	return x>y;
}
int erfen(int a)
{
	int l=0,r=n*m,mid;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (f[mid]==a) return mid;
		else if (f[mid]<a) r=mid-1;
		else l=mid+1;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int nm=n*m;
	for (int i=0;i<nm;i++) scanf("%d",&f[i]);
	R=f[0];
	sort(f,f+nm,cmp);
	Ri=erfen(R);
	Ri++;
	ansm=int(ceil(Ri*1.0/n));
	if (ansm%2==1) ansn=Ri%n;
	else ansn=n-(Ri%n)+1;
	if (ansn==0) ansn=n;
	printf("%d %d",ansm,ansn);
	return 0;
}
