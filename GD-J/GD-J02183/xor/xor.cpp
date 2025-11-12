#include<bits/stdc++.h>
using namespace std;
int s[1145];
int n,k,cnt,ans;
int menu[1145][1145];
//int setting[1145][2],setlg,answers[1145][2],answerslg;//debuger
bool _xor(int from,int to)
{
	if(menu[from][to]!=-1)return menu[from][to];
	int skk=s[from];
	for(int i=from+1;i<=to;i++)
	{
		skk=skk^s[i];
	}
	menu[from][to]=skk;
	return skk==k;
}
void dfs(int x)
{
	if(x==n)
	{
		if(s[n]==k)cnt++;
//		if(cnt>ans)//
//		{
//			answerslg=setlg;
//			for(int i=1;i<=answerslg;i++)answers[i][0]=setting[i][0],answers[i][1]=setting[i][1];
//		}
		ans=max(ans,cnt);
		if(s[n]==k)cnt--;
		return;
	}
	if(x>n)
	{
//		if(cnt>ans)//
//		{
//			answerslg=setlg;
//			for(int i=1;i<=answerslg;i++)answers[i][0]=setting[i][0],answers[i][1]=setting[i][1];
//		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(_xor(x,i))
		{
//			setting[++setlg][0]=x;//
//			setting[setlg][1]=i;//
			cnt++;
			for(int j=i+1;j<=n;j++)dfs(j);
			if(i==n)dfs(n+1);
//			setlg--;//
			cnt--;
		}
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		for(int j=1;j<=n;j++)menu[i][j]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i);
	}
//	for(int i=1;i<=answerslg;i++)//
//	{
//		printf("%d %d\n",answers[i][0],answers[i][1]);//
//	}
	printf("%d",ans);
	return 0;
}
//kmax:1048576 smax:500000

//4 0
//2 1 0 3
