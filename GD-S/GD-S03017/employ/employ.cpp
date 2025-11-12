#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[2048],sum=0;
bool use[2048];
int fang[1145];
int n,m,ans=0;
string s;
void dfs(bool have[],int where[],int next,int past)
{
	//cout<<where[next]<<' ';
	//if (!(s[next]=='1'||where[next]>past))past++;
	if (next==n)
		{
		ans=0;
		int qian=0;
		for (int i=1;i<=n;i++)
			{
			if (where[i]>qian&&s[i-1]=='1')ans++;
			else qian++;
			if (ans>=m)break;
			}
		if (ans>=m)sum++,sum=sum%998244353;
		return;
		}
	for (int i=1;i<=n;i++)
		if (have[i]==0)
			{
			where[next+1]=c[i];
			have[i]=1;
			dfs(have,where,next+1,past);
			have[i]=0;
			}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
		{
		cin>>c[i];
		//if (c[i]==0)i--,n--;
		}
	//sort(c+1,c+1+n);  
	for (int i=1;i<=n;i++)
		{
		use[i]=1;
		fang[1]=c[i];
		dfs(use,fang,1,0);
		fang[1]=use[i]=0;
		}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
