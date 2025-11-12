#include<bits/stdc++.h>
using namespace std;
int n,q,ans,cun[200005];
string s0[200005],s1[200005],t0,t1;
bool pan(string x,string y)
{
	return x.size()<y.size();
}
bool panhuan(string y,string x,int z)
{
	for(int i=0;i<y.size();i++)
	{
		if(y[i]!=x[i+z])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	//freopen("我要玩原神","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n<=1003)
	{
		for(int i=0;i<n;i++)
		{
			cin>>s0[i]>>s1[i];
		}
		sort(s0,s0+n,pan);
		sort(s1,s1+n,pan);
		for(int i=1;i<=q;i++)
		{
			cin>>t0>>t1;
			int zuo,you,l,wei;
			you=(int)t0.size()-1;
			for(zuo=0;zuo<t0.size();zuo++)
			{
				if(t0[zuo]!=t1[zuo])
				{
					break;
				}
			}
			for(;you>=0;you--)
			{
				if(t0[you]!=t1[you])
				{
					break;
				}
			}
			l=you-zuo+1;
			for(wei=0;wei<n;wei++)
			{
				if(s0[wei].size()>=l)
				{
					break;
				}
			}
			for(;zuo>=0;zuo--)
			{
				for(int yy=you;yy<t0.size();yy++)
				{
					int pan111=0;
					for(int k=wei;k<n;k++)
					{
						if(s0[k].size()==yy-zuo+1)
						{
							pan111=1;
							if(panhuan(s0[k],t0,zuo)&&panhuan(s1[k],t1,zuo))
							{
								ans++;
								//cout<<zuo<<" "<<s0[k]<<" "<<t0<<'\n';
							}
						}
						else if(pan111!=0)
						{
							if(s0[k].size()!=yy-zuo+1)
							{
								break;
							}
							if(panhuan(s0[k],t0,zuo)&&panhuan(s1[k],t1,zuo))
							{
								ans++;
								//cout<<zuo<<" "<<s0[k]<<" "<<t0<<'\n';
							}
						}
						
					}
				}
			}
			cout<<ans<<'\n';
			ans=0;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cin>>s0[i]>>s1[i];
			int yi=0,er=0;
			for(int j=0;j<s0[i].size();j++)
			{
				if(s0[i][j]=='b')
				{
					yi=j;
				}
				if(s1[i][j]=='b')
				{
					er=j;
				}
			}
			cun[i]=er-yi;
		}
		sort(cun,cun+n);
		for(int i=1;i<=q;i++)
		{
			cin>>t0>>t1;
			int yi=0,er=0;
			for(int j=0;j<t0.size();j++)
			{
				if(t0[j]=='b')
				{
					yi=j;
				}
				if(t1[j]=='b')
				{
					er=j;
				}
			}
			int lu=er-yi;
			int l=lower_bound(cun,cun+n,lu)-cun;
			int r=upper_bound(cun,cun+n,lu)-cun;
			if(l!=n)
			{
				ans+=r-l+1;
			}
			cout<<ans<<'\n';
			ans=0;
		}
		
	}
	//cout<<'\n'<<"freopen!!!!!!!!!!";
	return 0;
}
