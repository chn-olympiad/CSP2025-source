#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cmath>
using namespace std;
int column,row;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,r=0;
	cin>>n>>m;
	vector<int> seat;
	for(int i=0;i<=n*m;i++)
	{
		int useless;
		cin>>useless;
		seat.push_back(useless);
	}
	r=seat[0];
	sort(seat.begin(),seat.end(),greater<int>());
	int cnt=1;
	for(vector<int>::iterator it=seat.begin();it!=seat.end();it++,cnt++)
	{
		if(*it==r)
		{
			column=ceil(cnt/(double)n);
			if(column%2==1)
			{
				row=cnt%n;
			}
			else
			{
				row=n+1-cnt%n;
			}
			break;
		}
	}
	cout<<row<<' '<<column;
	return 0;
}
