#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7; 
map<string,string>mp;
int len[N];
string s1[N],s2[N];
string get(string s,int l,int r)
{
	string p="";
	for(int i=l;i<=r;i++)
	{
		p+=s[i];
	}
	return p;
}
string nw(string s,int l,int r,string t)
{
	string p="";
	for(int i=l;i<=r;i++)
	{
		s[i]=t[i-l];
	}
	return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout<<nw("xqmbz",1,3,"123");
	int n,q;
	cin>>n>>q;
	string t,t2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		mp[s1[i]]=s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		long long ans=0;
		cin>>t>>t2;
		int ql=t.size();
		for(int j=0;j<ql;j++)
		{
			for(int k=j;k<ql;k++)
			{
				string gt=get(t,j,k);
//				cout<<gt<<"->>";
				if(mp.count(gt))
				{
					string np=mp[gt];
//					cout<<j<<"->"<<k<<" ";
					string nt=nw(t,j,k,np);
//					cout<<nt<<" ";
					if(nt==t2)
					{
						ans++;
					}
				}
//				cout<<"\n";
			}
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
