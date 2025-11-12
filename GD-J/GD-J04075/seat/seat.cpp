#include<bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	bool is_;
};
bool cmp(stu& a,stu& b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<stu> lst(n*m);
	for(int i=0;i<n*m;i++)
	{
		cin>>lst[i].score;
		if(i==0) lst[i].is_=true;
	}
	sort(lst.begin(),lst.end(),cmp);
	int k=0;
	for(int j=1;j<=m;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				if(lst[k].is_)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(lst[k].is_)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
