#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long dl[N],n,k,ans,fa[2][N];
void pd(long long top)
{
	long long yes=0;
//	cout<<"PD:top="<<top<<'\n';
	for(int i=1;i<=top;i++)
	{
//		cout<<"now:(top["<<i<<"])"<<fa[0][i]<<'-'<<fa[1][i]<<":\n";
		long long yh=dl[fa[0][i]];
		for(int j=fa[0][i]+1;j<=fa[1][i];j++)
		{
//			cout<<"    "<<yh<<"^="<<dl[j]<<"->yh=";
			yh^=dl[j];
//			cout<<yh<<'\n';
		}
//		cout<<" so:yh="<<yh<<"\n";
		if(yh!=k)
		{
//			ans=max((long long)i,ans);
//			return ;
			continue;
		}
		else
		{
			yes++;
		}
	}
//	cout<<"so:yes="<<yes<<"\n\n";
	ans=max(ans,yes);
	return ;
}
void dfs(int x,int y,long long top)
{
	if(y==n)
	{
		fa[0][top]=x;
		fa[1][top]=y;
		pd(top);
		return ;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			if(y+i<=n&&x+j<=n)
			{
				fa[0][top]=x;
				fa[1][top]=y;
				pd(top);
				dfs(x+j,y+i,top+1);
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>dl[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
/*
kugua助我QAQ QwQ ^_^ :) OoO
%%%kugua
%%%limoxuan
%%%shuiyixiang
%%%zhangchengrui
%%%caiziyu
*/