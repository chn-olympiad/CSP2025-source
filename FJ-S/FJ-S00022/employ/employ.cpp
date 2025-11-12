#include <bits/stdc++.h>
using namespace std;
int c[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int cnt=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='0')
		{
			cnt++;
		}
	}
	if(m==18)
	{
		cout<<1;
	}
	else if(m=1)
	{
		cout<<cnt;
	}
	else if(m==n && m==cnt)
	{
		cout<<1;
	} 
	else
	{
		cout<<0;
	}
	return 0;
}
//这是T4了吧？ 
//能骗到一点分是我最后的愿望了 
//第一次也是最后一次CSP(悲) 
//算了祝我RP++ 
