#include<bits/stdc++.h>
using namespace std;
int p[512],n,m,r[512];
long long ans;
char ch[512];
bool weixuan[512],s[512];
bool work()
{
	int sum=0,gp=0;
	for(int i=1;i<=n;i++)
	  if(gp<r[p[i]])
	  {
		  if(s[i])sum++;
		  else
			gp++;
	  }
	  else
		gp++;
	if(sum>=m)return 1;
	else
	  return 0;
}
void pai(int cs)
{
	if(cs>n)
	{
		ans+=work();
		if(ans>=998244353)ans-=998244353;
	}
	for(int i=1;i<=n;i++)
	  if(weixuan[i]==0)
	  {
	  	  weixuan[i]=1;
	  	  p[cs]=i;
	  	  pai(cs+1);
	  	  weixuan[i]=0;
	  }
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",ch);
	for(int i=1;i<=n;i++)
	  if(ch[i-1]=='0')s[i]=0;
	  else
		s[i]=1;
	for(int i=1;i<=n;i++)
	  cin>>r[i];
	pai(1);
	cout<<ans;
	return 0;
}