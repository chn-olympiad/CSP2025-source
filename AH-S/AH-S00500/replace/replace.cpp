#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[1000000],b[1000000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
	{
		string x,y;
		cin>>x>>y;
		int ns=0;
		ns=x.size();
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			int xx1=a[j].size(),yy1=b[j].size();
			if(xx1==yy1)
			{
				int z1,z2,f=1;
				z1=x.find(a[j]);
				z2=y.find(b[j]);
				if(z1<0 || z2<0 || z1!=z2)
					f=0;
				for(int k=0;k<z1;k++)
					if(x[k]!=y[k])
					{
						f=0;
						break;
					}
				for(int k=z1+xx1;k<ns;k++)
					if(x[k]!=y[k])
					{
						f=0;
						break;
					}
				sum+=f;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}
