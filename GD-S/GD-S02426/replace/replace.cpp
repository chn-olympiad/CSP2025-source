#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstdio>
#include<cstring>
#include<utility>
#include<map>
using namespace std;
#define pr pair<string,string>
struct node
{
	string lx,ly;
}tr[200100];
string la,lb;
string lz,ll,lv;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>tr[i].lx>>tr[i].ly;
	}
	if(q>100000000)
	{
		for(i=1;i<=q;i++)
		cout<<"0"<<endl;
		return 0;
	}
	for(i=1;i<=q;i++)
	{
		int sum=0;
		cin>>la>>lb;
		for(int j=1;j<=n;j++)
		{
			int ans=0;
			int lk=lk-tr[j].lx.size();
			int l=0;
			for(int k=0;k<lk;k++)
			{
				for(int l=0;l<tr[j].lx.size();l++)
				{
					if(tr[j].lx[l]!=la[k+l])
					break;
				}
				if(l==tr[j].lx.size())
				{
					ans=k;
					break;
				}
			}
			if(ans>=0)
			{
				lz=tr[j].lx.substr(0,ans+1);
				ll=tr[j].lx.substr(ans+tr[j].lx.size(),la.size());
				lv=lz+tr[j].ly+ll;
			//	pr v=make_pair(lz,ll);
				if(lv==lb)
				{
					sum++; 
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
