#include<bits/stdc++.h>
#define int long long
using namespace std;
const int cxk=1e5+91;
int n,t,sum;
vector<int>v[5];
struct ikun
{
	int a,b,c;
	int f()
	{
		return max(a,max(b,c));
	}
	int F()
	{
		int d=f();
		if(a==d)
			return a-max(b,c);
		if(b==d)
			return b-max(a,c);
		return c-max(a,b);
	}
}k[cxk];
bool cmp(int x,int y)//按换组的代价排序 
{
	return k[x].F()<k[y].F(); 
}
void change(int h)
{
	int cnt=v[h].size();
	sort(v[h].begin(),v[h].end(),cmp);
	for(int i:v[h])
	{
		if(cnt>n/2)
			sum-=k[i].F();
		else 
			break;
		cnt--;
	}
}
void help()
{
	sum=0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].a>>k[i].b>>k[i].c;
		if(k[i].a>=max(k[i].b,k[i].c))
			v[1].push_back(i);
		else if(k[i].b>=max(k[i].a,k[i].c))
			v[2].push_back(i);
		else
			v[3].push_back(i);
		sum+=k[i].f();
	}
	int val=max(v[1].size(),max(v[2].size(),v[3].size()));
	if(val<=n/2)
	{
		cout<<sum<<"\n";
		return;
	}
	if(v[1].size()==val)
		change(1);
	else if(v[2].size()==val)
		change(2);
	else 
		change(3);
	cout<<sum<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	for(cin>>t;t--;help());
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
