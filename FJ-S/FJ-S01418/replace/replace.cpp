#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		string sx,sy;
		cin>>sx>>sy;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(s1[j]==sx&&s2[j]==sy)
			{
				cnt++;
			}
		}
		int l=0,r=sx.size(),f=0;
		string ss=" ";
		for(int j=0;j<sx.size();j++)
		{
			if(sx[j]!=sy[j])
			{
				ss+='1';
			}else{
				ss+='0';
			}
		}
		for(int j=0;j<ss.size();j++)
		{
			if(ss[j]=='1')
			{
				l=j;
				break;
			}
		}
		for(int j=ss.size()-1;j>=0;j--)
		{
			if(ss[j]=='1')
			{
				r=j;
				break;
			}
		}
		ss=" ";
		for(int j=l;j<=r;j++)
		{
			ss+=sx[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(s1[j]==ss)
			{
				ss=s2[j];
			}
		}
		if(ss==sy)
		{
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
