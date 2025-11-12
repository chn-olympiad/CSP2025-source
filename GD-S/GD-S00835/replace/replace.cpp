#include<bits/stdc++.h>
using namespace std;
long long n,q,opop;
string x,y,lop,a[1000005],b[1000005],qw,qwe,qww;
map<string,string>opl;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		opl[a[i]]=b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		opop=0;
		for(int i=1;i<=x.size();i++)
		{
			for(int j=i;j<=x.size();j++)
			{
				lop="";
				for(int u=i;u<=j;u++)
				{
					lop+=x[u-1];
				}
				if(opl[lop]!="")
				{
					qw="";
					for(int ll=0;ll<x.size();ll++)
					{
						if(ll!=0)
						{
							qw+=x[ll-1];
						}
						qwe="";
						for(int loo=0;loo<opl[lop].size();loo++)
						{
							qwe+=opl[lop][loo];
						}
						qww=qw+qwe;
						for(int loo=ll+(j-i)+1;loo<x.size();loo++)
						{
							qww+=x[loo-1];
						}
						if(qww==y)
						{
							opop++;
							break;
						}
					}
				}
			}
		}
		cout<<opop<<endl;
	}
	
	return 0;
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
