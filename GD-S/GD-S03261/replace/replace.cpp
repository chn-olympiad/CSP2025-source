#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
string tt1[200005],tt2[200005];
int ll[200005],zc[200005],qm[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int op=1;
	for (int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int cx1=0,cx2=0;
		zc[i]=s1.length();
		for (int j=0;j<s1.length();j++)
		{
			if (s1[j]=='b')
			{
				cx1=j;
				qm[i]=j-1;
				break;
			}
		}
		for (int j=0;j<s2.length();j++)
		{
			if (s2[j]=='b')
			{
				cx2=j;
				break;
			}
		}
		ll[i]=cx2-cx1;
		mp[s1]=s2;
		if (s1.length()>2000||s2.length()>2000)
		{
			op=2;
		}
	}	
	for (int i=1;i<=q;i++)
		{
			cin>>tt1[i]>>tt2[i];
			int c=tt1[i].length(),d=tt2[i].length();
			if (c>2000||d>2000)
			{
				op=2;
			}
		}
	if (n<=1000&&q<=1000)
	{
		if (op==1)
		{
			for (int i=1;i<=q;i++)
			{
				int c=tt1[i].length(),d=tt2[i].length();
				string t1=tt1[i],t2=tt2[i];
				if (c!=d)
				{
					cout<<0<<endl;
				}
				else
				{
					int l=0,r=0;
					int q=0;
					for (int i=0;i<c;i++)
					{
						if (t1[i]==t2[i])
						{
							if (q==1)
							{
								q=-1;
								r=i-1;
							}
						}
						else
						{
							if (q==0)
							{
								q=1;
								l=i;
							}
							if (q==-1)
							{
								cout<<0<<endl;
								q=-2;
								break;
							}
						}
					}
					if (q==1)
					{
						r=c-1;
					}
					if (q!=-2)
					{
						int ans=0;
						//cout<<l<<" "<<r<<endl;
						for (int i=0;i<=l;i++)
						{
							string s1="",s2="";
							for (int j=i;j<c;j++)
							{
								s1=s1+t1[j];
								s2=s2+t2[j];
								if (j>=r)
								{
									if (mp[s1]==s2)
									{
										ans=ans+1;
									}
								}
							}
						}
						cout<<ans<<endl;
					}
				}
			}
		}
		else
		{
			for (int i=1;i<=q;i++)
			{
				int c=tt1[i].length(),d=tt2[i].length();
				int tx1=0,tx2=0,zxc=0;
				string t1=tt1[i],t2=tt2[i];
				//cout<<t1<<endl;
				for (int j=0;j<t1.length();j++)
				{
					//cout<<t1[j];
					if (t1[j]=='b')
					{
						tx1=j;
						zxc=j-1;
						break;
					}
				}
				for (int j=0;j<t2.length();j++)
				{
					//cout<<t2[j];
					if (t2[j]=='b')
					{
						tx2=j;
						break;
					}
				}
				int tc=tx2-tx1;
				//cout<<tc<<" ";
				if (c!=d)
				{
					cout<<0<<endl;
				}
				else
				{
					int ans=0;
					for (int i=1;i<=n;i++)
					{
						if (ll[i]==tc&&zc[i]-qm[i]<=t1.length()-zxc&&qm[i]<=zxc)
						{
							ans=ans+1;
						}
					}
					cout<<ans<<endl;
				}
			}
		}
	}
	else
	{
		for (int i=1;i<=q;i++)
			{
				int c=tt1[i].length(),d=tt2[i].length();
				int tx1=0,tx2=0,zxc=0;
				string t1=tt1[i],t2=tt2[i];
				//cout<<t1<<endl;
				for (int j=0;j<t1.length();j++)
				{
					//cout<<t1[j];
					if (t1[j]=='b')
					{
						tx1=j;
						zxc=j-1;
						break;
					}
				}
				for (int j=0;j<t2.length();j++)
				{
					//cout<<t2[j];
					if (t2[j]=='b')
					{
						tx2=j;
						break;
					}
				}
				int tc=tx2-tx1;
				//cout<<tc<<" ";
				if (c!=d)
				{
					cout<<0<<endl;
				}
				else
				{
					int ans=0;
					for (int i=1;i<=n;i++)
					{
						if (ll[i]==tc&&zc[i]-qm[i]<=t1.length()-zxc&&qm[i]<=zxc)
						{
							ans=ans+1;
						}
					}
					cout<<ans<<endl;
				}
			}
	}
}
