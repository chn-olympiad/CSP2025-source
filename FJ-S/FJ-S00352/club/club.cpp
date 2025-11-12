#include<iostream>
#include<cstdio>
#include<algorithm> 
#define ll long long
using namespace std;
const int N = 5e5+10;
struct node
{
	ll a,b,c;
}v[N];
struct people
{
	ll pos,position,ltd,times;
}group[3][N];
ll t,n,ans,person[3],gr[3];
bool cmp(people x1,people x2)
{
	return x1.ltd < x2.ltd;
}
void sol()
{
	for(int i = 0;i < 3;i++)
		if(person[i] > n/2)
		{
			sort(group[i]+1,group[i]+1+gr[i],cmp);
			ll chgr = 1;
			while(person[i] > n/2)
			{
				bool k = 1;
				if(group[i][chgr].times)
				{
					bool flag = 1;
					for(int j = 0;j < 3;j++)
					{
						if(group[j][chgr].times == 0&&j != i)
						{
							group[i][chgr].pos = j;
							flag = 0;
							break;
						}
					}
					if(flag) 
					{
						ans -= group[i][chgr].ltd,person[i]--,k = 0;
						chgr++; 
					}
				}
				if(k)
				{
					ll leave;
					if(group[i][chgr].pos == 0) leave = v[group[i][chgr].position].a; 
					if(group[i][chgr].pos == 1) leave = v[group[i][chgr].position].b;
					if(group[i][chgr].pos == 2) leave = v[group[i][chgr].position].c;
					//cout<<ans<<" "<<group[i][chgr].ltd<<" "<<group[i][chgr].position<<" "<<leave<<endl;
					ans = ans - group[i][chgr].ltd;
					gr[group[i][chgr].pos]++;
					group[group[i][chgr].pos][gr[group[i][chgr].pos]].times++;
					person[i]--,person[group[i][chgr].pos]++,chgr++;	
				}
			}
		}
	cout<<ans;
	ans = 0;
	for(int i = 0;i < 3;i++)
	{
		person[i] = 0;
		gr[i] = 0;
		for(int j = 1;j <= n;j++)
		{
			group[i][j].ltd = 0;
			group[i][j].pos = 0;
			group[i][j].position = 0;
			group[i][j].times = 0;
		}
	}
}
void qwq()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>v[i].a>>v[i].b>>v[i].c;
		ll maxn = v[i].a,per = 0;
		if(maxn < v[i].b) maxn = v[i].b,v[i].b = v[i].a,v[i].a = maxn,per = 1;
		if(maxn < v[i].c) maxn = v[i].c,per = 2,v[i].c = v[i].a,v[i].a = maxn;
		ans += maxn;
		person[per]++;	
		gr[per]++;
		if(v[i].b > v[i].c) group[per][gr[per]]= {1,i,maxn-v[i].b,0};
		else group[per][gr[per]]= {2,i,maxn-v[i].c,0};
	}
	/*for(int i = 0;i < 3;i++)
		for(int j = 1;j <= gr[i];j++) 
			cout<<group[i][j].ltd<<" "<<group[i][j].pos<<" "<<group[i][j].position<<" "<<group[i][j].times<<endl;*/
	sol();
	cout<<endl;
}
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		qwq();
		t--;
	}
	return 0;
}
/*
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
