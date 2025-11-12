#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string st1,st2,k1[200005],k2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>k1[i]>>k2[i];
	}
	while(q--) 
	{
		int ans=0;
		cin>>st1>>st2;
		for(int i=1;i<=n;i++)
		{
			string nst1=st1,nst2=st2;
			while(nst1.find(k1[i])!=-1&&nst2.find(k2[i])!=-1)
			{
				string x="",y="";
				for(int j=0;j<nst1.find(k1[i]);j++) x+=nst1[j];
				for(int j=nst1.find(k1[i])+k1[i].size();j<nst1.size();j++) x+=nst1[j];
				
				for(int j=0;j<nst2.find(k2[i]);j++) y+=nst2[j];
				for(int j=nst2.find(k2[i])+k2[i].size();j<nst2.size();j++) y+=nst2[j];
				if(x==y) 
				{
					ans++;
				}
				else 
				{
					break;
				}
				nst1=x,nst2=y; 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


