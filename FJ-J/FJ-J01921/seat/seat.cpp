#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,g,pos,a[N];
bool cmp(int aa,int bb) {return aa>bb;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	g=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	  if(a[i]==g) pos=i;
	int res=(pos-1)%n+1,cnt=(pos+n-1)/n;
	printf("%d %d",cnt,(cnt&1?res:n-res+1));
	return 0;
}
