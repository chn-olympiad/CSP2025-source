#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3)
	{
		if(a[0]+a[1]>a[2]) cout<<1;
		else cout<<0;
	}
	else if(n==4)
	{
		for(int i=0;i<2;i++)
			for(int j=i+1;j<3;j++)
				for(int k=j+1;k<4;k++)
					if(a[i]+a[j]>a[k]) ans++;
					else break;
		if(a[0]+a[1]+a[2]>a[3]) ans++;
	}
	else if(n==5)
	{
		for(int i=0;i<3;i++)
			for(int j=i+1;j<4;j++)
				for(int k=j+1;k<5;k++)
					if(a[i]+a[j]>a[k]) ans++;
					else break;
		for(int i=0;i<2;i++)
			for(int j=i+1;j<3;j++)
				for(int k=j+1;k<4;k++)
					for(int x=k+1;x<5;x++)
						if(a[i]+a[j]+a[k]>a[x]) ans++;
						else break;
		if(a[0]+a[1]+a[2]+a[3]>a[4]) ans++;
	}
	else 
	{
		for(int i=0;i<n-2;i++)
			for(int j=i+1;j<n-1;j++)
				for(int k=j+1;k<n;k++)
					if(a[i]+a[j]>a[k]) ans++;
					else break;
		for(int i=0;i<n-3;i++)
			for(int j=i+1;j<n-2;j++)
				for(int k=j+1;k<n-1;k++)
					for(int x=k+1;x<n;x++)
						if(a[i]+a[j]+a[k]>a[x]) ans++;
						else break;
		for(int i=0;i<n-4;i++)
			for(int j=i+1;j<n-3;j++)
				for(int k=j+1;k<n-2;k++)
					for(int x=k+1;x<n-1;x++)
						for(int y=4;y<n;y++)
						if(a[i]+a[j]+a[k]+a[x]>a[y]) ans++;
						else break;
		for(int i=0;i<n-5;i++)
			for(int j=i+1;j<n-4;j++)
				for(int k=j+1;k<n-3;k++)
					for(int x=k+1;x<n-2;x++)
						for(int y=x+1;y<n-1;y++)
							for(int z=y+1;z<n;z++)
							if(a[i]+a[j]+a[k]+a[x]+a[y]>a[z]) ans++;
							else break;
	}
	cout<<ans;
	return 0;
 } 
