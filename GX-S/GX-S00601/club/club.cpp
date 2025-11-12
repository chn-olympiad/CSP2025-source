#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<ctime>
#include<cstdlib>
#define int long long
const int N=211985;
const int M=1000000007;
using namespace std;
char cvb;
int re()
{
	int dfg=0,fgh=1;
	cvb=getchar();
	while(cvb>'9'||cvb<'0')
	{
		if(cvb=='-') fgh=-1;
	cvb=getchar();
		}
	while(cvb>='0'&&cvb<='9')
	{
		dfg=(dfg<<1)+(dfg<<3)+cvb-'0';
	cvb=getchar();
		}
	return dfg*fgh;
}
int n,b[4],T,q,t[4],ans;
struct jg
{
	int val,x;
}a[N];
bool gz(jg xx1,jg xx2) {return xx1.val<xx2.val;}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=re();
	while(T--){
	n=re();
	t[1]=t[2]=t[3]=ans=0;
	for(int i=1;i<=n;i++)
	{
		b[0]=re();
		b[1]=re();
		b[2]=re();
		if(b[0]>b[1]&&b[0]>b[2]) a[i].x=0;
		else if(b[1]>b[2]) a[i].x=1;
		else a[i].x=2;
		a[i].val=min(b[a[i].x]-b[(a[i].x+1)%3],b[a[i].x]-b[(a[i].x+2)%3]);
		ans+=b[a[i].x];
		t[a[i].x+1]++;
		}
	sort(a+1,a+n+1,gz);
	q=0;
	if(t[1]>n/2) q=1;
	if(t[2]>n/2) q=2;
	if(t[3]>n/2) q=3;
	for(int i=1;i<=n&&t[q]>n/2&&q;i++)
	  if(a[i].x+1==q)
	  {
		  ans-=a[i].val;
		  t[q]--;
		  }
    printf("%lld\n",ans);
    }
	return 0;
}
