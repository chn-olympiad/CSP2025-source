#include <bits/stdc++.h>
#define Rp pair<int,int> 
using namespace std;
int list[100000][1000000];
struct Road{
	Rp con;
	int cost;
};
struct City{
	int _to[10000];
	int cost=0;
	bool is_village=false;
}city[500011];
int n,m,k;
void reset(){
	City classic;
	for(int i=0;i<n;i++)classic._to[i]=-1;
	for(int i=0;i<n;i++)city[i]=classic;
}
void search(){
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	reset();
	for(int i=0;i<m;i++){
		Road road;
		cin>>road.con.first>>road.con.second>>road.cost; 
		city[road.con.first]._to[road.con.second]=road.cost;
		city[road.con.second]._to[road.con.first]=road.cost;
	}
	for(int i=n;i<n+k;i++)
	{
		cin>>city[i].cost;
		city[i].is_village=true;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			city[i]._to[j]=x;
			city[j]._to[i]=x;
		}
	}
	cout << search();
	return 0;
}
