#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a1[200001],a2[200001],b1,b2;
bool pd(string x,string y,string a,string b,int l)
{
	for(int i=0;i<l;i++)
	{
		if(y[i]!=b[i]) return 0;
	}
	for(int i=0;i<x.size();i++,l++)
	{
		if(x[i]!=y[l]||a[i]!=b[l]) return 0;
	}
	for(int i=l;i<y.size();i++)
	{
		if(y[i]!=b[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>a2[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>b1>>b2;
		int b1s=b1.size(),b2s=b2.size();
		if(b1s!=b2s)
		{
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<b1s;k++)
			{
				if(a1[j][0]==b1[k]&&a2[j][0]==b2[k])
				{
					if(pd(a1[j],b1,a2[j],b2,k))
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
