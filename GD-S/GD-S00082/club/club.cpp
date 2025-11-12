#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,ret;
struct dat
{
	int x,y,z;
}a[N];
void solve()
{
	scanf("%d",&n),ans=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	
	sort(a+1,a+1+n,[](dat c,dat d){return c.x>d.x;});
	ret=0;
	for(int i=1;i<=n/2;i++) ret+=a[i].x;
	for(int i=n/2+1;i<=n;i++) ret+=max(a[i].y,a[i].z);
	ans=max(ans,ret);
	
	sort(a+1,a+1+n,[](dat c,dat d){return c.y>d.y;});
	ret=0;
	for(int i=1;i<=n/2;i++) ret+=a[i].y;
	for(int i=n/2+1;i<=n;i++) ret+=max(a[i].x,a[i].z);
	ans=max(ans,ret);
	
	sort(a+1,a+1+n,[](dat c,dat d){return c.z>d.z;});
	ret=0;
	for(int i=1;i<=n/2;i++) ret+=a[i].z;
	for(int i=n/2+1;i<=n;i++) ret+=max(a[i].x,a[i].y);
	ans=max(ans,ret);
	
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
