#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
#define Mod 998244353
int n,m;
int c[505];
string op;
bool lv[505];
int jie(int x)
{
	if(x==0||x==1) return 1;
	long long ans=1;
	for(long long i=2;i<=x;i++) ans*=i;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>op;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(op[i-1]=='1') 
		{
			lv[i]=1;
			flag++;
		}
	}
	if(m==n)
	{
		if(flag<n)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	else if(flag==n)
	{
		cout<<jie(n)/jie(n-m)%Mod<<endl;
		return 0;
	}
	return 0;
}