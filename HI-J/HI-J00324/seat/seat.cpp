#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a1,n,m,x=0,y=0;
	cin>>n>>m;
	vector<int> s;
	cin>>a1;s.push_back(a1);
	for(int i=1;i<n*m;i++)
	{
		int a;cin>>a;
		s.push_back(a);
	}
	sort(s.begin(),s.end(),cmp);
	bool ans=false;
	int h=-1;
	for(int i=1;i<=m;i++)
	{
		if(ans==false)
		{
			for(int j=1;j<=n;j++)
			{
				h++;
				if(s[h]==a1)
				{
					x=i;y=j;
					break;
				}
			}
		}
		else	
		{
			for(int j=n;j>=1;j--)
			{
				h++;
				if(s[h]==a1)
				{
					x=i;y=j;
					break;
				}
			}
		}
		ans=!ans;
	}
	cout<<x<<' '<<y;
	return 0;
}

