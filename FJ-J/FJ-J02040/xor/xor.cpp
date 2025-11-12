//++RP
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500011];
int ans;
int xoq[1001][1001];
struct noe
{
	int b,e;
} xok[1011];
int nk;
//n^n=0;
//0^n=n;
//…Ën=2^k
//‘Ú n^(n+1)=1;
//   n^(n-1)=n+n-1=2n-1;
//   (n-1)^(n-2)=1;
//   (n+2)^(n+3)=1;
int t1=1;
int t10=1;
int f=0;
inline bool cmp(noe aa,noe bb)
{
	if(aa.b==bb.b)
		return aa.e<bb.e;
	return aa.b<bb.b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i(1); i<=n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>1&&f==0)
			t1=0,t10=0,f=1;
		else if(a[i]==0&&f==0)
			t1=0,f=1;
	}
	if(n==1)
	{
		if(a[1]==0)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(a[1]==0&&a[2]==0)
		{
			cout<<2;
			return 0;
		}
		int xo=a[1]^a[2];
		if(xo==0||a[1]==0||a[2]==0)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(k==0)
	{
		if(t1==1)
		{
			cout<<n/2;
			return 0;
		}
		if(t10==1)
		{
			for(int i(1); i<=n; i++)
			{
				if(a[i]==0)
					ans++;
				else
				{
					if(a[i]==1&&a[i+1]==1)
					{
						ans++;
						i++;
						continue;
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
	if(t10==1)
	{
		for(int i(1);i<=n;i++)
		{
			if(a[i]==1)
				ans++;
		}
		cout<<ans;
		return 0;
	}
	//cong  i  kai shi
	for(int i(1); i<=n; i++)
	{
		for(int j(i); j<=n; j++)
		{
			if(i==j)
				xoq[i][i]=a[i];
			else
				xoq[i][j]=xoq[i][j-1]^a[j];
			if(xoq[i][j]==k)
			{
				nk++;
				xok[nk].b=i;
				xok[nk].e=j;
			}
		}
	}
	sort(xok+1,xok+nk+1,cmp);
	for(int i(1); i<=nk; i++)
	{
		int nowans=1;
		int nt=xok[i].e;
		for(int j(i+1); j<=k; j++)
		{
			if(xok[j].b>nt)
			{
				cout<<1;
				nowans++;
				nt=xok[j].e;
			}
		}
		ans=max(ans,nowans);
	}
	cout<<ans;
	return 0;
}
//4 0 2 1 0 3
