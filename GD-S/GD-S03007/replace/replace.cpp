#include<bits/stdc++.h>
using namespace std;
long long n,m,q,L[200100],R[200100],k[200100];
string a[200100],b[200100],c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		m=a[i].size();
		int l=0,r=m-1;
		for(;l<m&&a[i][l]==b[i][l];l++){}
		for(;r>=0&&a[i][r]==b[i][r];r--){}
		L[i]=l;
		k[i]=m;
		R[i]=r;
	}
	for(;q--;)
	{
		cin>>c>>d;
		m=c.size();
		if(m!=d.size())
		{
			cout<<0<<"\n";
		}
		else
		{
			long long l=0,r=m-1,s=0;
			for(;l<m&&c[l]==d[l];l++){}
			for(;r>=0&&c[r]==d[r];r--){}
			if(l==m)
			{
				for(int i=1;i<=n;i++)
				{
					if(L[i]==k[i]&&a[i][0]==c[0])
					{
						s+=max(0ll,m-k[i]+1);
					}
				}
			}
			else
			{
				//cout<<l<<' '<<r<<'\n';
				for(int i=1;i<=n;i++)
				{
					if(L[i]<=l&&(R[i]-L[i]==r-l)&&k[i]-R[i]<=m-r&&(L[i]==0||a[i][L[i]-1]==c[l-1])&&(R[i]==k[i]-1||a[i][R[i]+1]==c[r+1]))
					{
						//cout<<i<<' '<<L[i]<<' '<<R[i]<<'\n';
						bool ok=1;
						for(int j=L[i],k=l;j<=R[i];j++,k++)
						{
							if(a[i][j]!=c[k]||b[i][j]!=d[k])
							{
								ok=0;
								break;
							}
						}
						s+=ok;
					}
				}
			}
			cout<<s<<"\n";
		}
		
	}
}
