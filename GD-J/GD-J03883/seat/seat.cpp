#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,in,who,where;
vector<int>a;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	a.reserve(105);
	for(int i=1;i<=n*m;i++)
	{
		cin>>in;
		a.push_back(in);
	}
	who=a[0];
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==who)
		{
			where=i;
			break;
		}
	}
	where++;
	int l;
	l=where/n;
	if(where%n!=0)l++;
	cout<<l<<' ';	
	if(l%2!=0)
	{	
		if(where%n==0)cout<<n;
		else cout<<where%n;
	}
	else{
		if(where%n==0)cout<<1;
		else cout<<n-(where%n)+1;
	}
	return 0;
}

