#include<bits/stdc++.h>
using namespace std;
bool flag;
string s1;
long long  n,m,c[1000100],ji=0;
long long  jie(long long  a1,long long a2)
{
	long long  ans=1;
	for(;a1>=(a1-a2+1);a1--)
	ans=(ans%998244353)*a1;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=0;i<s1.size();i++)
	{
	if(s1[i]==1) ji++;
	if(s1[i]==0)flag=1;
	}
	if(flag==1&&n==m)cout<<0<<endl;
	else{
	long long ans=(((jie(m,m)*jie(m,n-m))%998244353)*(m+1))%998244353;
	if(flag==0)cout<<ans<<endl;
	//else cout<<rand[0,m]<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
