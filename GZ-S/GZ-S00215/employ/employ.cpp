//GZ-S00215 贵阳市第一中学  李啸峰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[20],p[20],Ans,Mod=998244353;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		Ans=1;
		for(int i=1;i<=n;i++)
			Ans=Ans*i%Mod;
		cout<<Ans<<endl;
		return 0; 
	}
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		do{
			int cnt=0,tmp=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1]=='0'||cnt>=c[p[i]])
					cnt++;
				else
					tmp++;
			}
			if(tmp>=m)
				Ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<Ans<<endl;
		return 0;
	}
	return 0;
}
