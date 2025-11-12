#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[10000005],pos,cnt;
struct pr
{
	int d1,d2;
	bool operator<(const pr t)const
	{
		if(d2!=t.d2)return d2<t.d2;
		return d1<t.d1;
	}
}d[10000005];
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void _wr(ll x)
{
	if(x>9)_wr(x/10);
	putchar(x%10+48);
}
void write(ll x,char f='_')
{
	if(x<0)putchar('-');
	x=abs(x);
	_wr(x);
	if(f!='_')cout<<f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	int ___jc=1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		if(a[i]>1)___jc=0;
	if(1e3<=n&&k<=1&&___jc==1)
	{
		int ___cnt=0,___ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)___cnt++;
			else ___ans+=___cnt/2+1,___cnt=0;
		}
		cout<<___ans;
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int s=a[j]^a[i-1];
			if(s==k)d[pos].d1=i,d[pos++].d2=j;
		}
	sort(d,d+pos);
	int _ds=-1;
	for(int i=0;i<pos;i++)if(_ds<d[i].d1)cnt++,_ds=d[i].d2;
	cout<<cnt;
	return 0;
}