#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
struct node
{
	int d1,d2,d3;
};

int T;
int n;

//bool cmp(node x,node y)
//{
//	if(x.d1!=y.d1) return x.d1<y.d1;
//	else if(x.d2!=y.d2) return x.d2<y.d2;
//	else return x.d3<y.d3;
//}

bool cmp(pair<int,int>& x,pair<int,int>& y){return x.first>y.first;}
vector<node> s(N);
int Ans(int idxx)
{
	vector<pair<int,int> > f1,f2,f3;
	for(int i=0;i<n;i++)
	{
		int x;
		if(idxx==1) x=max(max(s[i].d1,s[i].d2),s[i].d3);
		if(idxx==2)
		{
			x=max(max(s[i].d1,s[i].d2),s[i].d3);
			if(s[i].d1==x) x=max(s[i].d2,s[i].d3);
			if(s[i].d2==x) x=max(s[i].d1,s[i].d3);
			if(s[i].d3==x) x=max(s[i].d2,s[i].d1);
		}
		if(idxx==3)
		{
			x=max(max(s[i].d1,s[i].d2),s[i].d3);
			if(s[i].d1==x) x=min(s[i].d2,s[i].d3);
			if(s[i].d2==x) x=min(s[i].d1,s[i].d3);
			if(s[i].d3==x) x=min(s[i].d2,s[i].d1);
		}
		
		if(x==s[i].d1) f1.push_back(make_pair(x,i));
		else if(x==s[i].d2) f2.push_back(make_pair(x,i));
		else if(x==s[i].d3) f3.push_back(make_pair(x,i));
	}
	int l1=f1.size(),l2=f2.size(),l3=f3.size();
	if(!((l1>n/2)||(l2>n/2)||(l3>n/2)))
	{
		int ans=0;
		for(int i=0;i<l1;i++) ans+=f1[i].first;
		for(int i=0;i<l2;i++) ans+=f2[i].first;
		for(int i=0;i<l3;i++) ans+=f3[i].first;
		return ans;
	}
	else
	{
		if(l1>n/2)
		{
			sort(f1.begin(),f1.end(),cmp);
			int ans=0;
			for(int i=0;i<n/2;i++) ans+=f1[i].first;
			for(int i=n/2;i<l1;i++)
			{
				int x=f1[i].second;
				ans+=max(s[x].d2,s[x].d3);
			}
			for(int i=0;i<l2;i++) ans+=f2[i].first;
			for(int i=0;i<l3;i++) ans+=f3[i].first;
			return ans;
		}
		if(l2>n/2)
		{
			sort(f2.begin(),f2.end(),cmp);
			int ans=0;
			for(int i=0;i<n/2;i++) ans+=f2[i].first;
			for(int i=n/2;i<l2;i++)
			{
				int x=f2[i].second;
				ans+=max(s[x].d1,s[x].d3);
			}
			for(int i=0;i<l1;i++) ans+=f1[i].first;
			for(int i=0;i<l3;i++) ans+=f3[i].first;
			return ans;
		}
		if(l3>n/2)
		{
			sort(f3.begin(),f3.end(),cmp);
			int ans=0;
			for(int i=0;i<n/2;i++) ans+=f3[i].first;
			for(int i=n/2;i<l3;i++)
			{
				int x=f3[i].second;
				ans+=max(s[x].d1,s[x].d2);
			}
			for(int i=0;i<l1;i++) ans+=f1[i].first;
			for(int i=0;i<l2;i++) ans+=f2[i].first;
			return ans;
		}
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>s[i].d1>>s[i].d2>>s[i].d3;
		int ans1=Ans(1),ans2=Ans(2),ans3=Ans(3);
		cout<<max(max(ans1,ans2),ans3)<<"\n";
		s.clear();
	}
	
	return 0;
}
