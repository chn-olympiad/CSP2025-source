#include<bits/stdc++.h>
using namespace std;
const int M=500010,N=25;
int n,k,a[M],ch[M*N][2],cnt,s,l;
void ins(int x)
{
	int p=0;
	for(register int i=19,j;i>=0;i--)
	{
		j=((x>>i)&1);
		if(!ch[p][j])ch[p][j]=++cnt;
		p=ch[p][j];
	}
}
int query(int x)
{
	x^=k;
	int p=0;
	for(register int i=19,j;i>=0;i--)
	{
		j=((x>>i)&1);
		if(!ch[p][j])return 0;
		p=ch[p][j];
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
//		cout<<a[i]<<' ';
	}
	ins(0);
	for(register int i=1;i<=n;i++)
	{
		if(query(a[i]))
		{
			++s;
//			cout<<l<<' '<<i<<'\n';
			l=i;
			for(register int j=0;j<=cnt;j++)
				ch[j][0]=ch[j][1]=0;
			cnt=0;
			ins(a[i]);
		}
		else ins(a[i]);
	}
	cout<<s;
	return 0;
}
