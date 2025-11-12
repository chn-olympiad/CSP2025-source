#include<bits/stdc++.h>
#define pb push_back
#define lli long long
using namespace std;
lli c[100001];
static const lli mod=998244353;
lli fact(lli n) 
{
	lli res=1;
	for(int i=1;i<=n;i++)
		res*=i,res%=mod;
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,t,cnt=0;
	string s;
	cin>>n>>m;
	t=n;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
		if(c[i]==0)
			t-=1,cnt+=1,cerr<<i<<" ";
	//cerr<<t<<endl;;
	bool flg=1;
	for(auto i:s)flg=flg&&(i=='1'),t-=(i=='0');
	if(t<m)cout<<0,exit(0);
	if(t==m)cout<<1,exit(0);
	if(flg)
		cout<<fact(m),exit(0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
