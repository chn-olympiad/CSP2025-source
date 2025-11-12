#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
long long ans=0;
bool s1[505];
int c[505];
long long jc(int x)
{
	long long ans=1;
	for(int i=2;i<=x;i++)
	{
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int w[505];
int main()
{
	int cnt2=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flagA=1,flagB=1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		s1[i+1]=s[i]-'0';
		if(s1[i+1]!=1)flagA=0;
		else cnt2++;
	}
	for(int i=1;i<=n;i++)
	{
		w[i]=i;
		cin>>c[i];
		if(c[i]==0)flagB=0;
	}
	if(m>cnt2){
		cout<<0;
		return 0;
	}
	if(flagA&&flagB){
		cout<<jc(n);
		return 0;
	}
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s1[i]==1&&(i-cnt-1)<c[w[i]])
				cnt++;
			if(cnt>=m){
				ans++;
				break;
			}
			if(i+m-cnt>n)break;
		}
		ans%=mod;
	}while(next_permutation(w+1,w+n+1));
	cout<<ans;
	return 0;
}

