#include<bits/stdc++.h>
using namespace std;
string x,y;
map<string,string> a;
int n,q;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[x]=y;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>x>>y;
		if(x.size()!=y.size()) 
		{
			cout<<0<<endl;
			continue;
		}
		string z,l;
		for(int j=0;j<x.size();j++)
		{
			z+=x[j],l+=y[j];
			if(x[j+1]!=y[j+1]) 
			{
				string s,d;
				for(int h=j+1;h<x.size();h++)
				{
					s+=x[h],d+=y[h];
					if(x[h+1]==y[h+1]&&a[s]==d&&h!=x.size()-1) 
					{
						ans++;
					}
				}
			}
			if(a[z]==l) 
			{
				bool dz=true;
				for(int h=j+1;h<x.size();h++) if(x[h]!=y[h]) 
				{
					dz=false;
				}
				if(dz) 
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
