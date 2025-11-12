#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;

const int MAXN=100000+5;
int n,T;
vector<int>b[5],x;

struct node
{
	int x,y,z;
}a[MAXN];

int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		ll sum=0;
		b[1].clear();b[2].clear();b[3].clear();
		for(int i=1;i<=n;i++)
		{
			sum+=max(a[i].x,max(a[i].y,a[i].z));
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x) b[1].push_back(i);
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y) b[2].push_back(i);
			else b[3].push_back(i);
		}
		int id=-1;
		if((int)b[1].size()>n/2) id=1;
		if((int)b[2].size()>n/2) id=2;
		if((int)b[3].size()>n/2) id=3;
		if(id==-1)
		{
			cout<<sum<<endl;
			continue;
		}
		x.clear();
		for(int i=0;i<b[id].size();i++)
		{
			if(id==1) x.push_back(a[b[id][i]].x-max(a[b[id][i]].y,a[b[id][i]].z));
			else if(id==2) x.push_back(a[b[id][i]].y-max(a[b[id][i]].x,a[b[id][i]].z));
			else x.push_back(a[b[id][i]].z-max(a[b[id][i]].y,a[b[id][i]].x));
		} 
		sort(x.begin(),x.end());
		for(int i=0;i<b[id].size()-n/2;i++) sum-=x[i];
		cout<<sum<<endl;
	}
	return 0;
}
//by Matrix_Power

