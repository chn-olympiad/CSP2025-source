#include<bits/stdc++.h>
using namespace std;
struct str
{
	string one,two;
}zc[100005];
string re(string mom,string son,string where)
{
	int place=mom.find(son),len=son.length();
	for(int i=0;i<len;i++)
		mom[place+i]=where[i];
	return mom;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string come,go;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>zc[i].one>>zc[i].two;
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>come>>go;
		for(int j=1;j<=n;j++)
		{
			if(come.find(zc[j].one)!=-1)//?
			{
				string td=re(come,zc[j].one,zc[j].two);
				if(td==go)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
