#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int mod=998244353;
int n,m;
int ans;
char c1;
int s[N],c[N],p[N];
void slove(int m1,int step,int sum)
{
	//cout<<m1<<' '<<step<<' '<<sum<<endl;
	if(m1>=m)
	{
		ans++;
	}
	if(step>n) return;
	if(s[step]==0) 
	{
		for(int j=1;j<=n;j++) 
		{
			if(c[j]>=sum&&p[j]==0) 
			{
				p[j]=1;
				slove(m1,step+1,sum+1);
				p[j]=0;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]>=sum&&p[i]==0)
			{
				p[i]=1;
				slove(m1+1,step+1,sum);
				p[i]=0;
			}
		}
	}
	
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c1;
		s[i]=(int)c1-(int)'0';
		//cout<<s[i]<<' ';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18)
	{
		slove(0,1,1);
		cout<<ans;
	}
	else
	{
		int op=n;
		for(int i=1;i<=n;i++)
		{
			if(c[i]<=0) op--;
		}
		cout<<op<<' ';
		ans=op;
		op--;
		for(int i=2;i<=n;i++)
		{
			if(op==0) break;
			ans*=op;
			ans%=mod;
			op--;
			//cout<<ans<<endl;
		}
		cout<<ans;
	}
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
40+16+25(0)+0=56pt
燃尽了
是我菜还是ccf发力了 
只能转战文化课了
byebye，OI
能进代码奇葩大赏吗 
*/
