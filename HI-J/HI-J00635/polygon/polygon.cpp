#include<bits/stdc++.h>
using namespace std;
int n;
int a[6000],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	if(n>=3)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k]) ans++;

	if(n>=4)
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int q=k+1;q<=n;q++)
					if(a[i]+a[j]+a[k]>a[q]) ans++;
	if(n>=5)
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int q=k+1;q<=n;q++)
					for(int x=q+1;x<=n;x++)
					if(a[i]+a[j]+a[k]+a[q]>a[x]) ans++;
					
	if(n>=6)
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int q=k+1;q<=n;q++)
					for(int x=q+1;x<=n;x++)
						for(int y=x+1;y<=n;y++)
							if(a[i]+a[j]+a[k]+a[q]+a[x]>a[y]) ans++;
	if(n>=7)
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int q=k+1;q<=n;q++)
					for(int x=q+1;x<=n;x++)
						for(int y=x+1;y<=n;y++)
							for(int z=y+1;z<=n;z++)
								if(a[i]+a[j]+a[k]+a[q]+a[x]+a[y]>a[z]) ans++;
	cout<<ans;
	return 0;
}
