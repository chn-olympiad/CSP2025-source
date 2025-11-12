#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n;
int ans;
int cnt1,cnt2,cnt3,a[maxn],b[maxn],c[maxn];
void solve()
{
	scanf("%d",&n);
	cnt1=cnt2=cnt3=ans=0;
	for(int i=1;i<=n;i++)
	{
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		int D=max(A,max(B,C));
		ans+=D;
		if(D==A)
		{
			a[++cnt1]=A-max(B,C);
		}
		else if(D==B)
		{
			b[++cnt2]=B-max(A,C);
		}
		else
		{
			c[++cnt3]=C-max(A,B);
		}
	}
	if(cnt1>n/2)
	{
		sort(a+1,a+cnt1+1);
		for(int i=1;i<=cnt1-(n/2);i++)ans-=a[i];
	}
	if(cnt2>n/2)
	{
		sort(b+1,b+cnt2+1);
		for(int i=1;i<=cnt2-(n/2);i++)ans-=b[i];
	}
	if(cnt3>n/2)
	{
		sort(c+1,c+cnt3+1);
		for(int i=1;i<=cnt3-(n/2);i++)ans-=c[i];
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
} 
