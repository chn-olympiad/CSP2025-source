#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m;
int a[15][15];
void go_z(pii &p)
{
	if(p.second%2==1)
	{
		if(p.first<n)
			p.first++;
		else
			p.second++;
	}
	else
	{
		if(p.first>1)
			p.first--;
		else
			p.second++;
	}
}
vector<int>fenshu;
bool cmp(int first,int second)
{
	return first>second;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int x;cin>>x;
		fenshu.push_back(x);
	}
	int r=fenshu[0];
	sort(fenshu.begin(),fenshu.end(),cmp);
	pii z={1,1};
	for(int i=1;i<=n*m;i++)
	{
		if(fenshu[i-1]==r)
		{
			cout<<z.second<<" "<<z.first;
			return 0;
		}
		go_z(z);
	}
	return 0;
}
