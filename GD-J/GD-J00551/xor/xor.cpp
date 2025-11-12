#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500002];
int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int y=0,h=0,op=1,ans=0;
	while(k!=0)
	{
		h+=op*(k%2);
		k=k/2;
		op=op*10;
	}
	k=h;
	h=0;
	int kl=1;
	for(int i=1;i<=n;i++)
	{
		int t,s=0,p=1;
		cin>>t;
		while(t!=0)
		{
			s+=p*(t%2);
			t=t/2;
			p=p*10;
		}
		a[i]=s;
		if(y==0)
		h=i;
		y+=s;
		int r=1;
		for(int j=y;j>0;j/=10)
		{
			if(j%10==2)
			y-=2*r;
			r=r*10;
		}
		if(s==k&&y!=k)
		ans++,y=0;
		if(y==k)
		ans++,y=0;
		if(y>k)
		{
			op=0;
			for(int q=i;q>=h;q--)
			{
				int yu=op;
		  		op+=a[q];
		  		int ry=1;
				for(int rt=op;rt>0;rt/=10)
				{
					if(rt%10==2)
					op-=2*ry;
					ry=ry*10;
				}
				if(op==k)
				{
					ans++;
					y=0;
					q=h;
					break;
				}
				else
				if(op>k)
				{
					y=yu;
					q=h;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
