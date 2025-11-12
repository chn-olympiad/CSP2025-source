#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000009],ans,d[1000009];
string f[1000009],st[1000009];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		long long h=a[i];
		if(h==0)st[i]="0";
		while(h)
		{
			st[i]+=char(h%2+'0');
			h/=2;
		}
		string ss="";
	    for(int j=0;j<min(st[i].size(),f[i-1].size());j++)
	    {
	    	if(st[i][j]==f[i-1][j])ss+='0';
	    	else ss+='1';
		}
		for(int j=min(st[i].size(),f[i-1].size());j<max(st[i].size(),f[i-1].size());j++)
		{
			if(st[i].size()>f[i-1].size())ss+=st[i][j];
			else ss+=f[i-1][j];
		}
		bool bb=0;
		for(int j=0;j<ss.size();j++)
			if(ss[j]!='0'){bb=1;break;}
		if(bb==0)f[i]="0";
		else f[i]=ss;
	}
	long long bj=0;
	for(int i=1;i<=n;i++)
	   {
	   	string ss="";
	   	if(bj!=0)
	   	{
		    for(int j=0;j<min(f[i].size(),f[bj].size());j++)
		    {
		    	if(f[i][j]==f[bj][j])ss+='0';
		    	else ss+='1';
			}
				for(int j=min(f[i].size(),f[bj].size());j<max(f[i].size(),f[bj].size());j++)
			{
				if(f[i].size()>f[bj].size())ss+=f[i][j];
				else ss+=f[bj][j];
			}
		}
		else ss=f[i];
		int h=0,s=1;
		for(int j=0;j<ss.size();j++)
		{
			h+=(ss[j]-'0')*s;
		s*=2;
		}
		if(h==k)ans++,bj=i;
	}
	cout<<ans;

    return 0;
}
