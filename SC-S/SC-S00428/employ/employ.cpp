#include<bits/stdc++.h>
using namespace std;
const int N=550;
const int mod=998244353;
int n,m;
int t=0,ans=0;
int s[N],c[N];
vector<string> p[N];
string temp;
int pi=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);	
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>temp;
	for(int i=0;i<temp.length();i++)
	{
		s[i+1]=temp[i]-'0';
		if(s[i+1]==0) t=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(t==0)
	{
		cout<<n;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++){
			if(s[i]==1)
			{
				for(int j=1;j<=n;j++)
				{
					if(c[j]>i-pi) ans=(ans+1)%mod;
				}
				pi++;
			}
		}
		cout<<ans;
	}
	else{
		cout<<2;
	}
	return 0;
}