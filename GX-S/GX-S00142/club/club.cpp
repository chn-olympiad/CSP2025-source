#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define maxn 10010

ll t,n,as[maxn][maxn],bumen[5];
ll ans;

void pai(ll a,ll b,ll c)
{
	if(a>b)
	{
		if(a>c) bumen[0]++,ans+=a;
		else bumen[2]++,ans+=c;
	}
	else
	{
		if(b>c) bumen[1]++,ans+=b;
		else bumen[2]++,ans+=c;
	}
}

void thi()
{
	for(int i=0;i<n;i++)
	{
		pai(as[i][0],as[i][1],as[i][2]);
	}
	cout<<ans<<endl;
	return;
}

void haoye()//te pan n=2 shi
{
	ll hao[5],ah=0,bh=0;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<3;i++)
		{
			hao[i]==as[j][i];
		}
		sort(hao,hao+3);
		ah+=hao[0];
	}
	cout<<ah<<endl;
	return;
}

void sec()
{
	for(int i=0;i<5;i++)
	{
		bumen[i]=0;
	}
	if(n<=2) haoye();
	else thi();
	return;
}

void sta()
{
	cin>>n;
	int i=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++) cin>>as[i][j];
	}
	i++;
	as[i][0]==0;as[i][1]==0;as[i][2]==0;
	sec();
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++) {sta();}
	return 0;
}