#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+5,M=1e6+5,e6=1e6;
int n,q;
struct sss
{
	string s1,s2;
	int len;
	bool friend operator<(sss x,sss y) {return x.len<y.len;}
}s[N];
struct ttt
{
	string s1,s2;
}t[N];
vector<int> v[55];
int bs[N][2];
int bt[N][2];
struct _
{
	int l,r,num;
};
vector<_> mp[2*M];
map<int,int> cnt;

void subB()
{
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		int l1=s[i].s1.size(),l2=s[i].s2.size();
		for(int j=0;j<l1;j++)
			if(s[i].s1[j]=='b')
			{
				bs[i][1]=j;
				break;
			}
		for(int j=0;j<l2;j++)
			if(s[i].s2[j]=='b')
			{
				bs[i][2]=j;
				break;
			}
	}
	for(int i=1;i<=q;i++)
	{
		int l1=t[i].s1.size(),l2=t[i].s2.size();
		for(int j=0;j<l1;j++)
			if(t[i].s1[j]=='b')
			{
				bt[i][1]=j;
				break;
			}
		for(int j=0;j<l2;j++)
			if(t[i].s2[j]=='b')
			{
				bt[i][2]=j;
				break;
			}
	}
	for(int i=1;i<=n;i++)
	{
		int lll=min(bs[i][1],bs[i][2]);
		int rrr=s[i].len-max(bs[i][1],bs[i][2])-1;
		int dif=bs[i][1]-bs[i][2];
		cnt[dif]++;
		mp[dif+e6].push_back({lll,rrr,cnt[dif]});
	}
//	for(int i=1;i<=2*e6;i++)
//		if(!mp[i].empty())
//			for(auto j:mp[i])
//			  printf("%lld %lld %lld %lld\n",i-e6,j.l,j.r,j.num);
	for(int i=1;i<=q;i++)
	{
		int len=t[i].s1.size();
		int lll=min(bt[i][1],bt[i][2]);
		int rrr=len-max(bt[i][1],bt[i][2])-1;
		int dif=bt[i][1]-bt[i][2];
		int pl=0,pr=mp[dif+e6].size()-1,mid,tans=-1;
		while(pl<=pr)
		{
			mid=pl+(pr-pl)/2;
			if(mp[dif+e6][mid].l<=lll && mp[dif+e6][mid].r<=rrr)
			  tans=mid,pl=mid+1;
			else
			  pr=mid-1;
		}
		cout<<mp[dif+e6][tans].num<<'\n';
	}
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bool fb=1;
	int numb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
		s[i].len=s[i].s1.size();
		if(fb)
		{
			numb=0;
			int l1=s[i].s1.size();
			for(int j=0;j<l1;j++)
			{
				if(s[i].s1[j]=='b')
				  numb++;
				if(s[i].s1[j]!='a' && s[i].s1[j]!='b')
				{
					fb=0;
					break;
				}
			}
			if(numb>1)
			  fb=0;
		}
		if(fb)
		{
			numb=0;
			int l2=s[i].s2.size();
			for(int j=0;j<l2;j++)
			{
				if(s[i].s2[j]=='b')
				  numb++;
				if(s[i].s2[j]!='a' && s[i].s2[j]!='b')
				{
					fb=0;
					break;
				}
			}
			if(numb>1)
			  fb=0;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i].s1>>t[i].s2;
		if(fb)
		{
			numb=0;
			int l1=t[i].s1.size();
			for(int j=0;j<l1;j++)
			{
				if(t[i].s1[j]=='b')
				  numb++;
				if(t[i].s1[j]!='a' && t[i].s1[j]!='b')
				{
					fb=0;
					break;
				}
			}
			if(numb>1)
			  fb=0;
		}
		if(fb)
		{
			numb=0;
			int l2=t[i].s2.size();
			for(int j=0;j<l2;j++)
			{
				if(t[i].s2[j]=='b')
				  numb++;
				if(t[i].s2[j]!='a' && t[i].s2[j]!='b')
				{
					fb=0;
					break;
				}
			}
			if(numb>1)
			  fb=0;
		}
	}
	if(fb)
	{
//		cout<<"SSSS"<<'\n';
		subB();
		return 0;
	}
	for(int o=1;o<=q;o++)
	{
		for(int i=0;i<=50;i++)
		  v[i].clear();
		int l1=t[o].s1.size(),l2=t[o].s2.size();
		for(int i=0;i<l1;i++)
		  v[t[o].s1[i]-'a'].push_back(i);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int ls=s[i].s1.size();
			for(auto j:v[s[i].s1[0]-'a'])
			{
				if(l1-j<ls)
				  continue;
				string temp1=t[o].s1.substr(j,ls);
				if(temp1!=s[i].s1)
				  continue;
				string temp2=t[o].s1;
				for(int jj=0;jj<ls;jj++)
				  temp2[jj+j]=s[i].s2[jj];
				if(temp2==t[o].s2)
				  ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
