#include<bits/stdc++.h>
using namespace std;
struct Road
{
	int kind;
	int from;
	int to;
	int price;
};
int cnt = 0;
int minans = INT_MAX;
vector<Road> V;
int M[10005];
int W[10005];
void solve(int num)
{
	if(num >= V.size())
	{
		minans = min(minans,cnt);
		return;
	}
	solve(num + 1);
	bool flag = 0;
	if(!W[num])
	{
		flag  = 1;
		W[num] = 1;
		cnt += M[num];
	}
	cnt += M[num];
	solve(num + 1);
	cnt -= M[num];
	if(flag)
	{
		flag = 0;
		W[num] = 0;
		cnt -= M[num];
	}
	
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i < m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		V.push_back({0,u,v,w});
	}
	for(int i = 1;i <= k;i++)
	{
		int price;
		cin>>price;
		M[i] = price;
		for(int j = 1;j <= m;j++)
		{
			int x;
			cin>>x;
			V.push_back({i,i,j,x});
		}
	}
	{
		vector<Road>::iterator it;
		for(it = V.begin();it != V.end();it++)
		cout<<it -> from <<" "<<it -> to<<" "<<it -> price<<endl;
		cout<<endl;
	}
	solve(0);
	cout<<minans;
}
