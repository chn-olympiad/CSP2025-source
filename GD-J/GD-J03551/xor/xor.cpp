#include <iostream>
#include <algorithm>
using namespace std;
int n,k,a[500001],sum,cnt=0,lst=0,ans=0;
struct qwq
{
	int start,end;
}awa[500001];
bool cmp(qwq a,qwq b)
{
	if(a.end==b.end) return a.start>b.start;
	return a.end<b.end;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=i;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k)
			{
				awa[++cnt]=(qwq){i,j};
				//cout<<i<<j<<endl;
				break;
			}
		}
	}
	sort(awa+1,awa+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(awa[i].start>lst)
		{
			lst=awa[i].end;
			ans++; 
		}
	}
	cout<<ans<<endl;
	return 0;
}
//[0,60];
//ÉñÃØO(n^2)¹ý2*10^5ÑùÀý,->[0,80];
//qwq&awa forever
