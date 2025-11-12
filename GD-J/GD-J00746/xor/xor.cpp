#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[900001],sa[500010][25],len[500010],c[500101],lenc=1;
bool judge(int from,int to)
{
	int tmp[100001],lentmp=len[from];
//	cout<<len[from];
	for(int i=1;i<=len[from];i++)
	{
		tmp[i]=sa[from][i];
	}
	for(int i=from+1;i<=to;i++)
	{
		lentmp=max(lentmp,len[i]);
		for(int j=1;j<=lentmp;j++)
		{
			if(sa[i][j]!=tmp[j])
			{
				tmp[j]=1;
			}
			else
			{
				tmp[j]=0;
			}
		}
	}
	if(lentmp<lenc)
	{
		return false;
	}
//	for(int i=1;i<=lentmp;i++)
//	{
//		cout<<tmp[i];
//	}
//	cout<<endl;
	for(int i=1;i<=lentmp;i++)
	{
		if(tmp[i]!=c[i])
		{
			return false;
		}
	}
	return true;
}
void dfs(int from,int to,int cnt)
{
//	cout<<from<<" "<<to<<" "<<cnt<<" "<<endl;
	ans=max(ans,cnt);
	if(from>n || to>n || from>to)
	{
//		cout<<"abcd";
		return;
	}
	if(judge(from,to)==true)
	{
		dfs(to+1,to+1,cnt+1);
	}
	dfs(from,to+1,cnt);
	dfs(from+1,to,cnt);
}
void geta(int x,int pos)
{
	int cnt=1;
	if(x==0)
	{
		sa[pos][1]=0;
		cnt=2;
	}
	while(x!=0)
	{
		sa[pos][cnt]=x%2;
		cnt++;
		x/=2;
	}
	len[pos]=cnt-1;
//	cout<<sizeof(sa[pos]);
//	for(int q=1;q<=len[pos];q++)
//	{
//		cout<<sa[pos][q];
//	}
//	cout<<endl;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	while(k!=0)
	{
		c[lenc]=k%2;
		lenc++;
		k/=2;
	}
	lenc--;
//	cout<<lenc;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		geta(a[i],i);
	}
	dfs(1,1,0); 
	cout<<ans;
	return 0;
}
