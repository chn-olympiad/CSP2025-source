#include<bits/stdc++.h>
using namespace std;
const int maxn=105,mod=998244353;
int n,m,a[maxn],pm[maxn],tmp[maxn],cnt;
string s;
bool check()
{
	int tot=0,sum=0;//sum count refuse
	for(int i=1;i<=n;i++) 
	{
		if(sum>=tmp[i] || s[i-1]=='0') sum++;
		else tot++;
	}
	if(tot>=m)return 1;
	else return 0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=18)
	{
		for(int i=1;i<=n;i++) pm[i]=i;
		do{
			for(int i=1;i<=n;i++)
				{tmp[i]=a[pm[i]];}
			if(check()) cnt++;
		}while(next_permutation(pm+1,pm+n+1));
		cout<<cnt%mod;
	}
	return 0;
}
