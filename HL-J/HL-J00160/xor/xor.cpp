#include <bits/stdc++.h>//十转二已完成， 按位异或已完成，惜败 
using namespace std;
int a[110];
int ts(int x)
{
	int t=0;
	int s=1;
	while(x>=1)
	{
		t+=(x%2)*s;
		x/=2;
		s*=10;
	}
	return t;
	
}
//int xor(int x1,int x2)
//{
//	string sx1=tx(x1);
//	string sx2=tx(x2);
//	int x1l=sx1.length();
//	int x2l=sx2.length();
//	string s;
//	if(x1l>x2l)
//	{	s=sx1;
//		for(i=0;i<x2l;i++)
//		{
//			if(sx2[i]==sx1[x1l-x2l+i]&&sx2[i]==1)
//				s[x1l-x2l+i]=1;
//			else s[x1l-x2l+i]=0;
//		}
//	}
//	else 
//	{	s=sx2;
//		for(i=0;i<x1l;i++)
//		{
//			if(sx1[i]==sx2[x2l-x1l+i]&&sx1[i]==1)
//				s[x2l-x1l+i]=1;
//			else s[x2l-x1l+i]=0;
//		}
//	}
//	int sl=s.length();
//	int sn=0;
//	for(int i=0;i<sl;i++)
//	{
//		sn+=(sl-i)*10*sl[i];
//	}
//	return sn;
//}
int main()
{
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
int h=0;
if(n==1&&a[1]==k)	cout<<"1";
else if(n==2)
{
	if(a[1]==k)	h++;
	 if(a[2]==k) h++;
	if(a[1]==k&&a[2]==k)	h++;	
}
	cout<<h;
	return 0;
}

