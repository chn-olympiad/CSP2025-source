#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t=0;
	cin>>t;
	for(;t>0;t--)
	{
		int n = 0;
		cin>>n;
		int size1 = 0,size2 = 0,size3 = 0;
		vector<int> d;
		int ans = 0;
		//DP
		for(int i=0;i<n;i++)
		{
			//read
			int ina1,ina2,ina3;
			cin>>ina1>>ina2>>ina3;
			if(ina1>=ina2&&ina1>=ina3)
			{
				ans += ina1;
				size1++;int d1 = (ina1-ina2),d2=(ina1-ina3);
				if(d1>d2)d1=d2;
				d.push_back(d1);
			}
			else if(ina2>=ina1&&ina2>=ina3)
			{
				ans += ina2;
				size2++;int d1 = (ina2-ina1),d2=(ina2-ina3);
				if(d1>d2)d1=d2;
				d.push_back(d1);
			}
			else if(ina3>=ina1&&ina3>=ina2)
			{
				ans += ina3;
				size3++;int d1 = (ina3-ina1),d2=(ina3-ina2);
				if(d1>d2)d1=d2;
				d.push_back(d1);
			}
		}
		//out
		int out_range = 0;
		sort(d.begin(),d.end());
		if(size1>n/2)
			out_range =  size1-n/2;
		if(size2>n/2)
			out_range =  size2-n/2;
		if(size3>n/2)
			out_range =  size3-n/2;
		for(int k = 0;k < out_range; k++)
		{
			ans -= d[k];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
