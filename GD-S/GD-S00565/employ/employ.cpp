#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,Mod=998244353;
int n,m,a[maxn],ans,gg[maxn],h[maxn];
bool o[maxn],op[maxn];
void dfs(int x,int y,bool z[],int w,int g[])
{
//	for(int i=1;i<=n;i++) cout<<g[i]<<" ";
//	cout<<x<<" "<<y<<" "<<w;
//	cout<<endl;
	if(y>=n)
	{
		if(w>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(z[i]!=1)
		{
			g[y+1]=i;
			z[i]=1;
			if(o[y+1]==0||x>=a[i])
			{
				dfs(x+1,y+1,z,w,g);
			}
			else
			{
				dfs(x,y+1,z,w+1,g);
			}
			z[i]=0;
		} 
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	bool o1=0;
	cin>>n>>m;
	h[0]=1;
	for(int i=1;i<=n;i++) h[i]=h[i-1]*i%Mod;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		o[i+1]=s[i]-'0';
		if(o[i+1]!=1) o1=1;
	}
//	for(int i=1;i<=n;i++) cout<<o[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
//	if(o1==1)
//	{
//		int num1=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]==0) num1++;
//		}
//		if(num1==0) cout<<h[n]<<endl;
//		else if(n-num1<m) cout<<0<<endl;
//		else
//		{
//			
//		}
//		return 0; 
//	}
	sort(a+1,a+n+1);
	dfs(0,0,op,0,gg);
	cout<<ans%Mod<<endl;
	return 0; 
}
