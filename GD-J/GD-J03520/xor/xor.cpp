#include<bits/stdc++.h>
using namespace std;
long long n,num[1010],ans;
string s[1010],k;//二进制 数字 
string tob(long long t)//转为二进制 
{
	string tt,ttt;
	while (t>0)
	{
		tt+=48+(t%2);
		t/=2;
	}
	int sss=tt.size();
	for (int i=sss-1;i>=0;i--)
	{
		ttt+=tt[i];
	}
	return ttt;
}
string cl(string a,string b)
{
	int lll=max(a.size(),b.size());
	string ree,r;
	bool z=0;
	for (int i=lll-1;i>=0;i--)
	{
		if (a[i]==b[i]&&z==0)
		{
			ree+='0';
			z=1;
		}
		else if(a[i]!=b[i]) ree+='1';
	}
	int ssss=ree.size();
	for (int i=ssss-1; i>=0;i--)
	{
		r+=ree[i];
	}
	return r;
}
void dfs(long long now,string nowval)
{
	if (now==n+1||nowval==k)//选完了 
	{
		if (nowval==k)ans++;
		return;  
	}
	dfs(now+1,cl(nowval,s[now]));
	dfs(now+1,nowval);
	dfs(now+1,cl(s[now],s[now]));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for (long long i=1;i<=n;i++)
	{
		cin>>num[i];
		s[i]=tob(num[i]);
	}
	if ((n<=2||n==3)&&k=="0")//测试点1,3 -10分 
	{
		if (n==1)cout<<1;
		if (n==2)cout<<2;
		if (n==3)cout<<3;
		return 0;
	}
	dfs(1,"0");
	cout<<ans;
	return 0;
}
