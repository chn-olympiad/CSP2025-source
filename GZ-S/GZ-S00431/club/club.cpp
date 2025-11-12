//GZ-S00431 贵阳雅礼高级中学（贵阳市第九中学） 赵锦鹏 
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int n;
int a[maxn],b[maxn],c[maxn];
int aLi[maxn],bLi[maxn],cLi[maxn],aL,bL,cL;
bool cmpA(int i1,int i2)
{
	if (a[i1]>a[i2]) return true;
	if (a[i1]<a[i2]) return false;
	if (b[i1]>b[i2] || c[i1]>c[i2]) return false;
	return true;
}
bool cmpB(int i1,int i2)
{
	if (b[i1]>b[i2]) return true;
	if (b[i1]<b[i2]) return false;
	if (c[i1]>c[i2]) return false;
	return true;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while (q--)
	{
		cin>>n;
		for (int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
		
		int minN,ans=0;
		for (int i=0;i<n;i++)
		{
			minN=min(min(a[i],b[i]),c[i]);
			ans+=minN;
			a[i]-=minN;
			b[i]-=minN;
			c[i]-=minN;
		}
		
		int maxN;
		for (int i=0;i<n;i++)
		{
			maxN=max(max(a[i],b[i]),c[i]);
			if (a[i]==maxN) aLi[aL++]=i;
			else if (b[i]==maxN) bLi[bL++]=i;
			else cLi[cL++]=i;
		}
		
		if (aL<bL)
		{
			swap(a,b);
			swap(aL,bL);
			swap(aLi,bLi);
		}
		if (bL<cL)
		{
			swap(b,c);
			swap(bL,cL);
			swap(bLi,cLi);
		}
		if (aL<bL)
		{
			swap(a,b);
			swap(aL,bL);
			swap(aLi,bLi);
		}
		
		int nP2=n/2;
		sort(aLi,aLi+aL,cmpA);
		while (aL>nP2) bLi[bL++]=aLi[--aL];
		sort(bLi,bLi+bL,cmpB);
		while (bL>nP2) cLi[cL++]=bLi[--bL];
		
		for (int i=0;i<aL;i++) ans+=a[aLi[i]];
		for (int i=0;i<bL;i++) ans+=b[bLi[i]];
		for (int i=0;i<cL;i++) ans+=c[cLi[i]];
		
		cout<<ans<<'\n';
	}
	return 0;
}
