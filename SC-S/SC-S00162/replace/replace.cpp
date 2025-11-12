#include<iostream>
#include<string>
using namespace std;
string a[1000005],b[1000005];
int aaa[1000005],bbb[1000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		for(int j=0;j<x.size;j++)
		{
			if (x[j]=='b') 
			{
				aaa[i]=j;
				bbb[i]=x.size()-j-1;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		string mubiao1,mubiao2;
		cin>>mubiao1>>mubiao2;
		if (mubiao1.size()!=mubiao2.size()) 
		{
			cout<<0<<"\n";
			continue;
		}
		else cout<<n;
	 } 
	 return 0;
}