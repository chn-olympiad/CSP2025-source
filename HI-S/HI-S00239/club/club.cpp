#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,haf,mad;
int a[4][100010];
int cmp(int a,int b)
{
	return a>b;
}
void AA()
{
	int b[4][100010];
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			b[j][i]=a[j][i];
		}
	}
	for(int i=1;i<=3;i++)
		{
			sort(b[i]+1,b[i]+n+1,cmp);
		}
		int ans=0;
		for(int i=1;i<=haf;i++)
		{
			ans+=b[1][i];
		}
		cout<<ans<<'\n';
		/*for(int i=1;i<=n;i++)
		{	
			for(int j=1;j<=3;j++)
			{
				cout<<a[j][i]<<' ';
			}
			cout<<'\n';
		}*/
}
void dfs1(int s,ll ans,int cnt1,int cnt2,int cnt3)
{
	mad=max(mad,ans);
	//cout<<ans<<' ';
	if(s==n+1) 
	{
		//cout<<'\n';
		return ;
	}
	if(cnt1<haf) dfs1(s+1,ans+a[1][s],cnt1+1,cnt2,cnt3);
	if(cnt2<haf) dfs1(s+1,ans+a[2][s],cnt1,cnt2+1,cnt3);
	if(cnt3<haf) dfs1(s+1,ans+a[3][s],cnt1,cnt2,cnt3+1);
}
void BB()
{
	mad=0;
	dfs1(1,0,0,0,0);
	cout<<mad<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		haf=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[j][i];
			}
		}
		bool flag=0; 
		for(int i=1;i<=n;i++)
		{
			if(a[2][i]!=0) flag=1;	
		}
		bool flag2=0; 
		for(int i=1;i<=n;i++)
		{		
			if(a[3][i]!=0) flag2=1;	
		}
		if(flag==0 && flag2==0) AA();
		else BB();
	}
	return 0;
} 
