#include<bits/stdc++.h>
using namespace std;
int n,b[500005][3],cnt=1,f[500005];
long long k,ans,a[500005],v,xo;
bool pd()
{
	bool bo=true;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			bo=false;
			break;
		}
	}
	return bo;
}
bool pd1(int x,int y)
{
	bool bo=true;
	for(int i=x;i<=y;i++)
	{
		if(f[i]==1) bo=false;
	}
	return bo;
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		if(pd())
		{
			cout<<n/2;
			return 0;
		}
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				ans++;
				i++;
			}else{
				if(a[i+2]==a[i+1]) i+=1;
				else if(a[i+2]==a[i+3]) i+=2;
				else if(a[i+3]==a[i+4])
				{
					ans++;
					i+=3;
				}else{
					ans++;
					i+=4;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i+1])
			{
				ans++;
				i++;
			}else{
				i+=2;ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	v=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k || i==n)
		{
			ans++;
			if(i==n && a[i]!=k) ans--;
			for(int j=1;v+j<i;j++)
			{
				for(;v<=i-2;v++)
				{
					for(int l=v;l<=v+j;l++)
					{
						xo=(xo xor a[l]);
					}
					if(xo==k)
					{
						b[cnt][0]=v;
						b[cnt][1]=v+j;
						b[cnt][2]=j;
					}
					xo=0;
				}
			}
			v=i+1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			if(b[j][2]==i && pd1(b[j][0],b[j][1]))
			{
				ans++;
				for(int l=b[j][0];l<=b[j][1];l++) f[l]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}