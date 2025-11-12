#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string x[N],y[N];
int n,q;
int L[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		L[i]=x[i].size();
	}
	for(int i=1;i<=q;i++)
	{
		int sum=0;
		string u,v;
		cin>>u>>v;
		for(int j=1;j<=n;j++)
		{
			for(int l=0,r=0;l<u.size(),r<v.size();l++,r++)
			{
				if(u[l]==x[j][0]&&v[r]==y[j][0])
				{
					int a=l+1,f=0;
					for(int k=1;k<L[j];k++)
					{
						if(u[a]!=x[j][k]&&v[a]!=y[j][k])
						{
							f=1;
							break;
						}
						a++;
					}
					if(!f)
					{
						for(int k=a;k<u.size();k++)
						{
							if(u[k]!=v[k])
							{
								f=1;
								break;
							}
						}
						if(!f)sum++;
					}
				}
				if(u[l]!=v[r])break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
