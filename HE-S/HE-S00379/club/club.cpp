#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q[4];

struct Person
{	// club1 club2 club3 
	int va,c1,c2,c3;
	int ma,mai,mi,mii;
} s[100006];
long long dp[100006];
inline void sortstu(Person &a)
{
	if(a.c1>=a.c2&&a.c1>=a.c3)
	{
		a.ma=a.c1;
		a.mai=1;
		if(a.c2>a.c3)
		{
			a.mi=a.c2;
			a.mii=2;
		}
		else
		{
			a.mi=a.c3;
			a.mii=3;
		}
		return;
	}else
	if(a.c2>=a.c1&&a.c2>=a.c3)
	{
		a.ma=a.c2;
		a.mai=2;
		if(a.c1>a.c3)
		{
			a.mi=a.c1;
			a.mii=1;
		}
		else
		{
			a.mi=a.c3;
			a.mii=3;
		}
		return;
	}else
	if(a.c3>=a.c1&&a.c3>=a.c2)
	{
		a.ma=a.c3;
		a.mai=3;
		if(a.c1>a.c2)
		{
			a.mi=a.c1;
			a.mii=1;
		}
		else
		{
			a.mi=a.c2;
			a.mii=32;
		}
		return;
	}
}
bool operator >(const Person &a,const Person &b) 
{
	//使sort从大到小排序 
	if(a.va!=b.va)
		return a.va<b.va;
	else
	if(a.c1!=b.c1)
		return a.c1<b.c1;
	else
	if(a.c2!=b.c2)
		return a.c2<b.c2;
	else
		return a.c3<b.c3;
}
bool operator <(const Person &a,const Person &b)
{
	return !(a>b);
}

void make_ans(void)
{
	memset(s,0,sizeof(s));
	memset(dp,0,sizeof(dp));
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	while(!q[3].empty()) q[3].pop();
	int n;
	cin>>n;
	int N=n/2;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].c1>>s[i].c2>>s[i].c3;
		s[i].va=(s[i].c1+s[i].c2+s[i].c3)/3;
		sortstu(s[i]);
	}
	sort(s+1,s+n+1);
	int cnt[4]={0,0,0,0};
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(cnt[1]<N&&cnt[2]<N&&cnt[3]<N)
		{
			dp[i]+=s[i].ma,cnt[s[i].mai]++;
			q[s[i].mai].push(-i);
			continue;
		}
		if(cnt[s[i].mai]>=N)
		{
			int tmp=-q[s[i].mai].top();
			if(s[i].mi+s[tmp].ma>s[i].ma+s[tmp].mi)
			{
				dp[i]+=s[i].mi;
				q[s[i].mii].push(-i);
				cnt[s[i].mai]++;
			}
			else
			{
				dp[i]+=0-s[tmp].ma+s[i].ma+s[tmp].mi;
				q[s[i].mai].pop();
				q[s[tmp].mii].push(-tmp);
				q[s[i].mai].push(-i);
				cnt[s[tmp].mii]++;
			}
		}
	}
	cout<<dp[n]<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
		make_ans();
	return 0;
}
