#include<bits/stdc++.h>
using namespace std;
//struct tree{
//	int sum,l,r,tf;
//}t[9999999];
int n,k;
int mapp[999999][999999];

int ai[999999];
inline int maxn(int a,int b)
{
	if(a>b)return a;
	return b;
}
inline int in2(int a)
{
	if(a<=1)return 1;
	if(a<=3)return 2;
	if(a<=7)return 3;
	if(a<=15)return 4;
	if(a<=31)return 5;
	if(a<=63)return 6;
	if(a<=127)return 7;
	if(a<=255)return 8;
	if(a<=511)return 9;
	if(a<=1023)return 10;
	if(a<=2047)return 11;
	if(a<=4095)return 12;
	if(a<=8191)return 13;
	if(a<=16383)return 14;
	if(a<=32767)return 15;
	if(a<=65535)return 16;
	if(a<=131071)return 17;
	if(a<=262143)return 18;
	if(a<=524287)return 19;
	if(a<=1048575)return 20;
	if(a<=2079151)return 21;
	return 9999;
}
inline int mi(int a,int k)
{
	if(k==0)return 1;
	for(int i=1;i<k;i++)
	{
		a*=a;
	}
	return a;
}
inline int xorr(int a,int b)
{
	int a2[99],b2[99];
	for(int i=1;i<=30;i++)
	{
		a2[i]=0;
	}
	for(int i=1;i<=30;i++)
	{
		b2[i]=0;
	}
	int a2l=in2(a);int b2l=in2(b);
	for(int i=a2l;i>=1;i--)
	{
		if(a>=mi(2,i-1))
		{
			a2[i]=1;
			a-=mi(2,i-1);
		}
		else
		{
			a2[i]=0;
		}
	}
	for(int i=b2l;i>=1;i--)
	{
		if(b>=mi(2,i-1))
		{
			b2[i]=1;
			b-=mi(2,i-1);
		}
		else
		{
			b2[i]=0;
		}
	}
	int c2[99];
	for(int i=1;i<=maxn(a2l,b2l);i--)
	{
		if(a2[i]==0&&b2[i]==1)c2[i]=1;
		if(a2[i]==1&&b2[i]==0)c2[i]=1;
		if(a2[i]==1&&b2[i]==1)c2[i]=0;
		if(a2[i]==0&&b2[i]==0)c2[i]=0;
	}
	int c=0;
	for(int i=1;i<=maxn(a2l,b2l);i++)
	{
		c+=c2[i]*mi(2,i-1);
	}
	return c;
}
inline int fitj(int i,int j)
{
	int d=ai[i];
	for(int q=i+1;q<=j;i++)
	{
		d=xorr(d,ai[q]);
		}	
	return 0;
}
int most=0;
inline int dfs(int l,int r)
{
	if(l==r){
		if(mapp[l][r]==k)return 1;
	}
	if(maxn(dfs(l,r-1),dfs(l+1,r))>=1)
	{
		return maxn(dfs(l,r-1),dfs(l+1,r));
	}
	else
	{
		if(mapp[l][r]==k)return 1;
		else
		{
			return 0;
		 } 
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf(" %d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>ai[i];
	}
//	built(1,1,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;i<=n;j++)
		{
			mapp[i][j]=fitj(i,j);
		}
	}
	cout<<dfs(1,n);
}
//天灵灵，地灵灵，Devc++求你别抽风。 
