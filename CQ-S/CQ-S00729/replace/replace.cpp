#include<iostream>
#include<algorithm>
using namespace std;
int n,q,s,e,cnt;
string a[1000][2];
string in,at,hd;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]; 
	}
	for(int i=1;i<=q;i++)
	{
		cin>>in>>at;
		if(in.size()!=at.size())
		{
			cout<<0<<endl;
			continue;
		}
		s=0,e=in.size()-1;
		for(int i=0;i<in.size();i++)
		{
			if(in[i]!=at[i])
			{
				s=i;
				break;
			}
		}
		for(int i=in.size()-1;i>=0;i--)
		{
			if(in[i]!=at[i])
			{
				e=i;
				break;
			}
		}		
		for(int i=s;i<=e;i++)
		{
			hd[++cnt]=in[i];
		}
	} 
	return 0;
} 

