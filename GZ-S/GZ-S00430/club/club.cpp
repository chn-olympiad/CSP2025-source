//GZ-S00430 毕节七星关东辰实验学校 赵锡元
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
ll n,t,ruend,tans[5];
ll viss[5],ru2,ru3,ru4;
ll bian;
struct qp
{
	ll now,ce;
}ru1[900860];
bool bi(qp a,qp b)
{
	return a.ce<b.ce;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ww=1;ww<=t;ww++)
	{
		cin>>n;
		tans[1]=0;tans[2]=0;tans[3]=0;
		viss[1]=0;viss[2]=0;viss[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>ru2>>ru3>>ru4;
			if(ru2>=ru3&&ru2>=ru4)
			{
				viss[1]++;tans[1]+=ru2;
				ru1[i].now=1;
				ru1[i].ce=min(ru2-ru3,ru2-ru4);
			}
			else
			{
				if(ru3>=ru2&&ru3>=ru4)
				{
					viss[2]++;tans[2]+=ru3;
					ru1[i].now=2;
					ru1[i].ce=min(ru3-ru2,ru3-ru4);
				}
				else
				{
					viss[3]++;tans[3]+=ru4;
					ru1[i].now=3;
					ru1[i].ce=min(ru4-ru3,ru4-ru2);
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			if(viss[i]>n/2)bian=i;
		}
		sort(ru1+1,ru1+n+1,bi);
		for(int i=1;i<=n&&viss[bian]>n/2;i++)
		{
			if(ru1[i].now==bian)
			{
				tans[bian]-=ru1[i].ce;
				viss[bian]--;
			}
		}
		cout<<tans[1]+tans[2]+tans[3]<<endl;
	}
	return 0;
}
