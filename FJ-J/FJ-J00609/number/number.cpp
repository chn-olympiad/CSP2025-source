#include<bits/stdc++.h>//freopen£¡£¡£¡£¡£¡£¡
using namespace std;
int a[1000005];
bool b[1000005];
int maxn=0;
int jishu=0;
/*
void f(int zong,int zhi)
{
	if(zong==0)
	{
		maxn=max(maxn,zhi);
		return;
	}
	for(int i=1;i<=jishu;i++)
	{
		if(b[i]==true)
		{
			b[i]=false;
			f(zong-1,zhi*10+a[i]);
			b[i]=true;
		}
	}
}
*/
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin>>t;
	for(int i=0;i<t.size();i++)
	{
		if(t[i]>='0'&&t[i]<='9')
		{
			jishu++;
			a[jishu]=t[i]-'0';
			b[jishu]=true;
		}
	}
	/*for(int i=1;i<=jishu;i++)
	{
		cout<<a[i]<<" ";
	}*/
	sort(a,a+jishu+1);
	for(int i=jishu;i>=1;i--)
	{
		cout<<a[i];
	}
	/*f(jishu,0);
	cout<<maxn;*/
	return 0;
}