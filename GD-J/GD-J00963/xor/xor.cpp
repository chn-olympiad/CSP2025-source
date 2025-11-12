#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int n,cnt,pf2[25],k,p;
bool yihuo[25][100005],mubiao[25],he[25];
bool fan(bool a,bool b)
{
	if((a&&b)||((!a)&&(!b)))return false;
	return true;
}
void fenjie(int x,int p)
{
	for(int i=20;i>=0;i--)
	{
		if(p>=pf2[i])
		{
			p-=pf2[i];
			yihuo[i][x]++;
		}
	}
}
bool yusuan(int i,int j)
{
	for(int i=0;i<=24;i++)he[i]==0;
	for(int q=i;q<=j;q++)
	{
		for(int m=0;m<=20;m++)he[m]=fan(he[m],yihuo[m][q]);
	}
	for(int i=0;i<=20;i++)if(he[i]!=mubiao[i])return false;
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=20;i>=0;i--)
	{
		if(k>=pf2[i])
		{
			k-=pf2[i];
			mubiao[k]++;
		}
	}
	pf2[0]=1;
	for(int i=1;i<=20;i++)pf2[i]=pf2[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		fenjie(i,p);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(yusuan(i,j))cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
