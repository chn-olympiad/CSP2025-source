#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
const int A=998;
const int B=244;
const int C=353;
int n,m;
string s;
int ans,c[N];
int jc(int x)
{
	int ans=1;
	while(x!=0)
	{
		ans=ans*x%A%B%C;
		x--; 
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(ans<m)
	{
		cout<<0;
	}
	else if(ans==m)
	{
		cout<<jc(ans)%A%B%C;
	}
	else
	{
		cout<<jc(m)%A%B%C*jc(ans)%A%B%C/jc(ans-m)%A%B%C;
	}
	
	return 0;
}
