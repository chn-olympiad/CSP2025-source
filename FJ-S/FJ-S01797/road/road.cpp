#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int c[100000];
int d[100000];
int e[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) 
	{
		cin>>a[i]>>b[i]>>c[i];
		d[i]=c[i];
	}
	sort(d+1,d+n+1);
	int p=1;
	int s=0;
	while(1) 
	{
		for(int i=1; i<=n; i++) 
		{
			if(d[p]==c[i]&&e[a[i]]==0||e[b[i]]==0) 
			{
				e[a[i]]=1;
				e[b[i]]=1;
				s+=c[i];
				p++;
			}
		}
		for(int i=1; i<=n; i++)
		{
			if(e[i]==0)
			{
				break;
			} 
			else
			{
				cout<<s<<endl;
				return 0;
			}
		}
	}
	return 0;
}
