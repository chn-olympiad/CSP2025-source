#include<iostream>
#include<cmath> 

using namespace std;

const int N=500005; 
int s[N],n,k,a,Max=-2147483640,M=-214748364;



void xyh(int l,int w)
{
	if(l>n+1) return ;
	if(l<=n+1)
	{
		Max=max(Max,w);
		if(l==n+1) return ;
	}
	

	int r=l;
	for(r=l;r<=n;r++)
	{
		if(s[r]-s[l-1]==k||s[l-1]-s[r]==k) 
		{
			xyh(r+1,w+1);
			break;
		}
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	s[1]=a;
	for(int i=2;i<=n;i++)
	{
		cin>>a;
		s[i]=s[i-1]^a;
		M=max(M,a);
	}
	xyh(1,0);
	cout<<Max;
	return 0;
}
/*
4 3
2 1 0 3

*/
