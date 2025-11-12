#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,M=5e6+5;
const ull P=1e9+7;
struct node{
	ull zt,yt,ay,by,h;
};
int n,q;
char sx[M],sy[M];
node a[N];
char tx[M],ty[M];
unordered_map<ull,int> mp1,mp2;
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",sx+1);
		scanf("%s",sy+1);
		int l=1,r=1;
		while(sx[l]!=0 and sx[l]==sy[l])
		{
			a[i].zt=a[i].zt*P+(sx[l]-'a'+1);
			l++;
		}
		while(sx[r]) r++;
		r--;
		ull val=1;
		while(r>=1 and sx[r]==sy[r])
		{
			a[i].yt=val*(sx[r]-'a'+1)+a[i].yt;
			val*=P;
			r--;
		}
		for(int j=l;j<=r;j++)
		{
			a[i].ay=a[i].ay*P+(sx[j]-'a'+1);
			a[i].by=a[i].by*P+(sy[j]-'a'+1);
		}
	}
	while(q--)
	{
		mp1.clear();
		mp2.clear();
		scanf("%s",tx+1);
		scanf("%s",ty+1);
		int l=1,r,len=1,len2=1;
		while(tx[len]) len++;len--;
		while(ty[len2]) len2++;len2--;
		r=len;
		if(len!=len2)
		{
			printf("0\n");
			continue;
		}
		ull val=0,t=1;
		while(l<=len and tx[l]==ty[l]) l++;
		while(r>=1 and tx[r]==ty[r]) r--;
		ull v1=0,v2=0;
		for(int i=l-1;i>=1;i--)
		{
			val=t*(tx[i]-'a'+1)+val;
			t*=P;
			mp1[val]=1;
		}
		val=0;
		for(int i=r+1;i<=len;i++)
		{
			val=val*P+(tx[i]-'a'+1);
			mp2[val]=1;
		}
		mp1[0]=1,mp2[0]=1;
		for(int i=l;i<=r;i++)
			v1=v1*P+(tx[i]-'a'+1),v2=v2*P+(ty[i]-'a'+1);
		int acans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].ay==v1 and a[i].by==v2 and mp1[a[i].zt]==1 and mp2[a[i].yt]==1)
				acans++;
		}
		printf("%d\n",acans);
	}
	return 0;
}
