#include<bits/stdc++.h>
using namespace std;
int xorr(int a,int b)
{
	int f=1048576,f2=20,f3=1048576,ans=0;
	int as[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int y=f2;y>=1;y--)
	{
		if(a>f)
		{
			as[y]++;
			a-=f;
		 } 
		if(b>f) 
		{
			as[y]++;
			b-=f;
		}
		f/=2;
	}
	for(int y=f2;y>=1;y--)
	{
		if(as[y]%2==1)
		{
			ans+=f3;
		}
		f3/=2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,c[100001],dfd=0,anns=0;
	cin>>a>>b;
	for(int q=1;q<=a;q++)
	{
		cin>>c[q]; 
	}
	dfd=c[1];
	for(int q=2;q<=a;q++)
	{
		dfd=xorr(dfd,c[q]);
		if(dfd==b) 
		{
			anns++;
			dfd=c[q+1];
			q++;
		}
	}
	cout<<dfd;
}
