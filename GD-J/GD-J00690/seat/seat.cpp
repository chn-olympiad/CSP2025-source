#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i=1;i<=n*m;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	int nows=0;
	int fen=v[0];
	sort(v.begin(),v.end());
	int nx=1,ny=1;
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i]==fen)
		{
			cout<<ny<<" "<<nx<<"\n";
			return 0;
		}
		if(nx==n&&ny%2==1)
		{
			ny++;
		}
		else if(nx==1&&ny%2==0)
		{
			ny++;
		}
		else
		{
			if(ny%2==1)nx++;
			else nx--;
		}
		nows++;
	}
	return 0;
}

