#include<bits/stdc++.h>
using namespace std;
int n,k,l,sum;
string s[500005];
int fywy(int x,int y)
{
	for(int i=x+1;i<=y;i++)
	{
		for(int j=0;j<l;j++)
		{
			if(s[x][j]==s[i][j])s[x][j]='0';
			else s[x][j]='1';
		}
	}
	int sb=0;
	for(int i=0;i<l;i++)
		sb=sb*2+int(s[x][i]-'0');
	return sb;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a==0)s[i]='0';
		while(a)
		{
			s[i]=char((a%2)+'0')+s[i];
			a/=2;
		}
		int c=s[i].size();
		l=max(l,c);
	}
	for(int i=1;i<=n;i++)
		while(s[i].size()<l)s[i]='0'+s[i];
	int z=0;
	for(int i=1;i<=n;i++)
	{
		z=i;
		for(int j=i;j<=n;j++)
		{
			if(fywy(i,j)==k)
			{
				sum++;
				z=j;
				break;
			}
		}
		i=z;
	}
	cout<<sum;
	return 0;
}
