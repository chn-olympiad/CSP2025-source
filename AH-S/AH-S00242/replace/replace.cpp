#include<bits/stdc++.h>
using namespace std;
int n,q,sum,sss,l,r,w1,w2;
int special=1;
string s1,s2,q1,q2,ss1,ss2,snull;
string x,y,z,xx,yy,zz;
map<string,string>mp;
map<int,int>imp;
vector<string>v1,v2;
int ww1[200048],ww2[200048];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		if(special==1)
		{
			v1.push_back(s1);
			v2.push_back(s2);
			sss=0;
			for(int j=0;j<s1.size();j++)
			{
				if(s1[j]=='b')sss++;
				else if(s1[j]!='a')special=0;
			}if(sss!=1)special=0;
			sss=0;
			for(int j=0;j<s2.size();j++)
			{
				if(s2[j]=='b')sss++;
				else if(s2[j]!='a')special=0;
			}if(sss!=1)special=0;
		}
		mp[s1]=s2;
	}mp[snull]="I_love_you_CCF!";
	if(special==1)
	{
		for(int i=0;i<v1.size();i++)
		{
			for(int j=0;j<v1[i].size();j++)
			{
				if(v1[i][j]=='b')ww1[i]=i;
				if(v2[i][j]=='b')ww2[i]=i;
			}
		}
		while(q--)
		{
			cin>>q1>>q2;
			if(q1.size()!=q2.size())
			{
				cout<<"0\n";
			}
			else
			{
				for(int i=0;i<q1.size();i++)
				{
					if(q1[i]=='b')w1=i;
				}
				for(int i=0;i<q2.size();i++)
				{
					if(q2[i]=='b')w2=i;
				}
				for(int i=0;i<v1.size();i++)
				{
					if(w1-w2==ww1[i]-ww2[i])
					{
						sum++;
					}
				}cout<<sum<<'\n';
			}
		}
		return 0;
	}
	while(q--)
	{
		cin>>q1>>q2;
		if(q1.size()!=q2.size())
		{
			cout<<"0\n";
		}
		else
		{
			sum=0;
			l=0,r=0;
			x.clear();
			xx.clear();
			z=q1;
			zz=q2;
			if(mp[q1]==q2)sum++;
			for(int i=0;i<q1.size();i++)
			{
				x.push_back(q1[i]);
				xx.push_back(q2[i]);
				y.clear(),yy.clear();
				z.clear(),zz.clear();
				for(int j=i+1;j<q1.size();j++)
				{	
					z.push_back(q1[j]);
					zz.push_back(q2[j]);
				}
				for(int j=i+1;j<q1.size();j++)
				{
					y.push_back(q1[j]);
					yy.push_back(q2[j]);
					z.erase(0);
					zz.erase(0);
					//cout<<x<<" "<<y<<" "<<z<<"    "<<xx<<" "<<yy<<" "<<z<<'\n';
					if(x==xx&&z==zz&&mp[y]==yy)
					{
						sum++;
					}
				}
			}cout<<sum<<'\n';
		}
	}
}
