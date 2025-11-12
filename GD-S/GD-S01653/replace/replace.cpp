#include<bits/stdc++.h>
using namespace std;
int n,q,s,b[100005],t,sp[10005][3],zs,sz[1000005],ans;
string st1[200005],st2[200005],ast1,ast2;
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>st1[i]>>st2[i];
		for(int k=0;k<st1[i].size();k++)
		{
			if(st1[i][k]!=st2[i][k]) sz[i]++;
		} 
	}
	for(int i=1;i<=q;i++)
	{
		int bg[100005];
		memset(bg,0,sizeof(bg));
		zs=0;
		cin>>ast1>>ast2;
		for(int j=1;j<=ast1.size();j++)
		{
			if(ast1[j]!=ast2[j]) zs++;
		}
		for(int j=1;j<=n;j++)
		{
			int q=0,sum=0;
			if(int(ast1.find(st1[j])==-1)||int(ast2.find(st2[j]))==-1||ast1.find(st1[j])!=ast2.find(st2[j]))continue;
			while(ast1.find(st1[j],q)<5000005&&ast1.find(st1[j])==ast2.find(st2[j]))
			{
				q=ast1.find(st1[j],q)+1;
				sum++;
			}
			bg[sz[j]*sum]++;
			for(int k=zs;k>zs-sz[j]*sum;k--)
			{
				bg[k]+=bg[k-sz[j]*sum];
			}
		}
		cout<<bg[zs]<<endl;
	}
	return 0;
}
