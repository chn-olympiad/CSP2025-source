#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e3+10,mod=998244353;
int n,a[maxn],f[maxn],ans=0,fl=0,st;
stack<int> s,s2;
void print()
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s2.push(s.top());
		s.pop();
	}
	while(!s2.empty())
	{
		s.push(s2.top());
		s2.pop();
	}
	cout<<endl;
}
void dfs(int cnt,int sum)
{
	if(fl==1)
	{
		return;
	}
	int minn=INT_MAX;
	if(!s.empty())
	{
		minn=s.top();
	}
	for(int i=st;i>=1;i--)
	{
		if(f[i]==0&&a[i]<=minn)
		{
			f[i]=1;
			s.push(a[i]);
//			print();
			dfs(cnt+1,sum+a[i]);
			s.pop();
			if(s.empty())
			{
				fl=1;
				return;
			}
//			print();
			f[i]=0;
		}
	}
	if(sum>2*a[st]&&cnt>=3)
	{
//		cout<<"final:";
//		print();
		ans+=1;
		ans%=mod;
		return;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(st=3;st<=n;st++)
	{
//		cout<<"next:"<<endl;
		memset(f,0,sizeof(f));
		fl=0;
		dfs(0,0);
	}
	cout<<ans<<endl;
	return 0;
}