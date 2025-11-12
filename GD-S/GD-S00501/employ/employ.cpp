#include<bits/stdc++.h>//我不行了，写暴力吧 
using namespace std;
int n,m,a[501],ans,stk[20];
char nd[501];
bool vis[20];
const int mod=998244353;
void slove(int x)
{
	if(x>n)
	{
		int cnt=0,num=0;
		for(int i=0;i<n;i++)
		{
			//cout<<stk[i+1]<<' '<<a[stk[i+1]]<<' '<<nd[i]<<endl;;
			if(a[stk[i+1]]<=cnt){cnt++;continue;}
			if(nd[i]=='1')num++;else cnt++;
			if(num>=m){ans++;ans%=mod;return ;}
		}//cout<<endl<<num<<endl;
	}
	for(int i=1;i<=n;i++)
	if(!vis[i])stk[x]=i,vis[i]=1,slove(x+1),vis[i]=0,stk[x]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>nd;
	for(int i=1;i<=n;i++)cin>>a[i];
	slove(1);cout<<ans;
	return 0;
}

