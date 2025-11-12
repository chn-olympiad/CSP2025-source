#include<bits/stdc++.h>
#define LL long long
const LL md1=998244353ll,md2=114514191ll;
using namespace std;
const int N=2e6+7;
int n,q;
int num,s[3][N];
void get(int i)
{
	num=0;char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	for(;ch>='a'&&ch<='z';ch=getchar())
		s[i][++num]=(int)ch-'a'+1;
}
LL hx1(int l,int r)
{
	LL rtn=0;
	for(int i=l;i<=r;i++)
	{
		rtn=(rtn*md1%md2+s[1][i])%md2;
		rtn=(rtn*md1%md2+s[2][i])%md2;
	}
	return rtn;
}
LL hx2(int l,int r)
{
	if(l<1||r>num)return 0;
	LL rtn=0;
	if(l<=r)
	for(int i=l;i<=r;i++)
		rtn=(rtn*md1%md2+s[1][i])%md2;
	else
	for(int i=l;i>=r;i--)
		rtn=(rtn*md1%md2+s[1][i])%md2;
	return rtn;
}
int ll[N],rr[N];
LL h1[N],h2[N],h3[N];
int ans;
LL anl[N],anr[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1,l,r;i<=n;i++)
	{
		get(1),get(2);
		l=1,r=num;
		for(;l<=num&&s[1][l]==s[2][l];l++);
		for(;r&&s[1][r]==s[2][r];r--);
		if(l>num){n--,i--;continue;}
		h1[i]=hx1(l,r),h2[i]=hx2(l-1,1),h3[i]=hx2(r+1,num);
		ll[i]=l-1,rr[i]=num-r;
//		printf("%lld %lld %lld %d %d\n",h1[i],h2[i],h3[i],l,r);
	}
	for(int i=1,l,r;i<=q;i++)
	{
		get(1),get(2);
		l=1,r=num;ans=0;
		for(;l<=num&&s[1][l]==s[2][l];l++);
		for(;r&&s[1][r]==s[2][r];r--);
		LL xx=hx1(l,r);
		for(int i=1;i<=num;i++)anl[i]=anr[i]=0;
		for(int j=l,k=1;j>=1;j--,k++)
			anl[k]=(anl[k-1]*md1%md2+s[1][j])%md2;
		for(int j=r+1,k=1;j<=num;j++,k++)
			anr[k]=(anr[k-1]*md1%md2+s[1][j])%md2;
		for(int j=1;j<=n;j++)
			if(h1[j]==xx&&h2[j]==anl[ll[j]]&&h3[j]==anr[rr[j]])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
