#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k;
int w[N][N],c[15],a[N][N];
int pan[N];//是否用过
int jia[N];//是否有价值 
vector<int> q[N];
vector<int> yi;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int q1,q2,q3;
		cin>>q1>>q2>>q3;
		w[q1][q2]=w[q2][q1]=q3;
		q[q1].push_back(q2);
		q[q2].push_back(q1);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	pan[1]=1;
	ll W=0;
	yi.push_back(1);
	for(int i=1;i<n;i++)//次数 
	{
		int xmin=0x3f3f3f,l1=0,l2=0;
		for(int j=0;j<yi.size();j++)//遍历走过的点 yi[j]
		{
			if(jia[yi[j]]==1)continue; 
			int bb=0;
			for(int z=0;z<q[yi[j]].size();z++)//连接点q[yi[j]][z] 
			{
				if(pan[q[yi[j]][z]]==1)continue;
				bb++;
				if(w[yi[j]][q[yi[j]][z]]<xmin)
				{
					xmin=w[yi[j]][q[yi[j]][z]];
					l1=yi[j],l2=q[yi[j]][z];
				}
			}
			if(bb==1)jia[yi[j]]=1;
		}
		pan[l2]=1;
		yi.push_back(l2);
		W+=xmin;
	}
	cout<<W<<endl;
}
