/*
14:34 开题
14:35 DP
14:41 贪心，发现性质
15：20 WC终于打完了114行 恶臭。。 
15：27 大样例全过，求AC  QwQ “_“。。 
*/ 
//	priority
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5];
pair<int,int> m(int t)
{
	int ans=1,maxn=a[t][1];
	for(int i=2;i<=3;i++)
	{
		if(a[t][i]>maxn)
		{
			maxn=a[t][i];
			ans=i;
		}
	}
	return {ans,maxn};
}
int vs(int t)
{
	int x[5];
	x[1]=a[t][1],x[2]=a[t][2],x[3]=a[t][3];
	sort(x+1,x+4);
	return x[3]-x[2];
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	int ans=0,s1=0,s2=0,s3=0;
	for(int i=1;i<=n;i++)
	{
		pair<int,int> p=m(i);
		ans+=p.second;
		if(p.first==1)s1++;
		else if(p.first==2)s2++;
		else   s3++;
	}
	if(max(s1,max(s2,s3))<=n/2)
	{
		cout<<ans<<"\n";
		return;
	}
	//有不满足的
	int flag,need=0;
	if(s1>n/2)
	{
		flag=1;need=s1-n/2;
	}
	else if(s2>n/2)
	{
		flag=2;need=s2-n/2;
	}
	else
	{
		flag=3;need=s3-n/2;
	}
//	cout<<"need:"<<need<<"\n";
	vector<int> vec;
	for(int i=1;i<=n;i++)
	{//fight 
		pair<int,int> p=m(i);
		if(p.first!=flag)continue;
		vec.push_back(i);
//		cout<<i<<" ";
	}
//	cout<<"\n";
	vector<int> va; 
//	cout<<"v:"; 
	for(auto t : vec)
	{
		int v=vs(t);
		va.push_back(v);
//		cout<<v<<" ";
	}
//	cout<<"\n";
//	cout<<need<<"\n";
	sort(va.begin(),va.end());
	for(int i=1;i<=need;i++)
	{
		ans-=va[i-1];
	}
	cout<<ans<<"\n";//<<"::\n";
	return;
}
int main()
{
//	feropen("club.in","r",stdin);我要上迷惑行为打赏！！！  QwQ... 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}	
	return 0;
}
