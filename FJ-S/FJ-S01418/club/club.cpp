#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a1[N],a2[N],a3[N];
int n,cnt1=0,cnt2=0,cnt3=0;
int mx=-1;
void dfs(int x,int sum)
{
	if(x==n)
	{
		mx=max(mx,sum);
		return;
	}
	if(cnt1+1<=(n/2))
	{
		cnt1++;
		dfs(x+1,sum+a1[x+1]);
		cnt1--;
	}
	if(cnt2+1<=(n/2))
	{
		cnt2++;
		dfs(x+1,sum+a2[x+1]);
		cnt2--;
	}
	if(cnt3+1<=(n/2))
	{
		cnt3++;
		dfs(x+1,sum+a3[x+1]);
		cnt3--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		cnt1=1;
		dfs(1,a1[1]);
		cnt1=cnt2=cnt3=0;
		cnt2=1;
		dfs(1,a2[1]);
		cnt2=cnt1=cnt3=0;
		cnt3=1;
		dfs(1,a3[1]);
		cnt3=cnt1=cnt3=0;
		cout<<mx<<endl;
		mx=-1;
	}
	return 0;
 } 
