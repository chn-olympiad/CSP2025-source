#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		string a1,a2;
		cin>>a1>>a2;
		mp[a1]=a2;
	}
	while(q--)
	{
		int ans=0;
		string t1,t2,t,tt;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		int len=t1.size();
		int pos1=0,pos2=len-1;
		while(t1[pos1]==t2[pos1])
		{
			pos1++;
		}
		while(t1[pos2]==t2[pos2])pos2--;
		for(int i=pos1;i<=pos2;i++)
		{
			t+=t1[i];
			tt+=t2[i];
		}
		for (int i=pos1;i>=0;i--)
		{
			if(i<pos1)
			{
				t=t1[i]+t;
				tt=t2[i]+tt;
			}
			string tmp=t,tmp2=tt;
			for (int j=pos2;j<=len-1;j++)
			{
				if(j>pos2)
				{
					t=t+t1[j];
					tt=tt+t2[j];
				}
				if(mp[t]==tt)ans++;
			}
			t=tmp;
			tt=tmp2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

