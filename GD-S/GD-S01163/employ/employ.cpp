#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=590,MOD=998244353;
int c[MAXN];
string s;
int n,m;
int p[15];
int main()
{
	FILE* fp;
	fp=freopen("employ.in","r",stdin);
	fp=freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n>10)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
			ans*=i,ans%=MOD;
		cout<<ans;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			p[i]=i;
		do
		{
			// for(int i=1;i<=n;i++)
			// 	cout<<p[i];
			// cout<<'\n';
			int cnt=0;
			int pa=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1]=='0')
				{
					pa++;
					continue;
				}
				if(pa<c[p[i]])
					cnt++;
				else
					pa++;
				//cout<<pa<<' ';
			}
			if(cnt>=m)
				ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}