#include<bits/stdc++.h>
using namespace std;

const int N=505,mod=998244353;
int n,m;
int a[N],p[N];
string s2,s;
void task_A()
{
	int _0=0;
	for(int i=1;i<=n;i++)if(a[i]==0)_0++;
	if(n-_0<m)
	{
		cout<<0;
		return;	
	}
	long long x=1;
	for(int i=2;i<=n;i++)x*=i,x%=mod;
	cout<<x;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=i;
		
	//--------------------------------- 
	for(int i=0;i<s.size();i++)s2+='1';
	if(s==s2)
	{
		task_A();
		return 0;
	}
	if(m==n)
	{
		int tag=0;
		for(int i=1;i<=n;i++)if(a[i]==0)tag=1;
		for(int i=0;i<s.size();i++)if(s[i]!='1')tag=1;
		if(!tag)task_A();
		else cout<<0;
		return 0;
	}
	//---------------------------------
	int ans=0;
	do{
		int cnt=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=a[p[i]]||s[i-1]=='0')cnt++;
			else if(s[i-1]=='1')cnt=0,l++;
		}
		if(l>=m)
			ans++,ans%=mod;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}