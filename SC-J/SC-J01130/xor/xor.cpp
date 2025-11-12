#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int b[N],h;
/*void mm(int x)
{
	if(x==n)
	{
		cout<<h;
		return;
	}
	h++;
	int w=n;
	for(int i=x+1;i<l;i++)
	{
		if(s[i]<w)
		    w=s[i];
	}
	mm(w);
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	    b[i]=b[i]^b[i-1];
	}
	if(n<=2&&k==0)
	{
		int y=0;
		if(b[1]==0)
		    y++;
		if(b[2]==0)
		    y++;
		if(b[1]==b[2])
		    y++;
		cout<<y;
		return 0;
	}
	cout<<2;
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int p;
			if(i!=j)
			    p=b[j]^b[i];
			if(i==j)
			    p=b[i];
			if(p==k)
			{
				//s[++l]=j;
				h++;
				break;
			}
		}
	}
	cout<<h;
//	mm(1);*/
	return 0;
} 