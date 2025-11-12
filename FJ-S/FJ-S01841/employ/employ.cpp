#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,x,sum;
int jc(int x)
{
	long long res=1;
	for(int i=1;i<=x;i++)
		res*=i,res%=998244353;
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&x),sum+=(x==0);
	n-=sum;
	if(s[0]=='1'&&n-sum>=m)
		cout<<jc(n);
	else
		cout<<0;
	return 0;
}
