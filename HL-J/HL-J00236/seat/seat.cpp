#include<bits/stdc++.h>
using namespace std;
bool x(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m = 0;
	int n = 0;
	cin>>n>>m;
	vector<int> o(n*m);
	vector< vector <int > > a(n,vector<int > (m,0));
	for(int i = 0;i < n*m;i++)
	{
		cin>>o[i];
	}
	int ans_num = o[0];
	sort(o.begin(),o.end(),x);
	int cnt_t = 0;
	for(int i = 0;i < n;i++)
	{
		if(i%2==0)
		{
			for(int j = 0;j < m;j++)
			{
				a[i][j] = o[cnt_t];
				if(a[i][j] == ans_num)
				{
					cout<<i+1<<" "<<j+1;
				}
				cnt_t++;
			}
		}
		else
		{
			for(int j = m-1;j >= 0;j--)
			{
				a[i][j] = o[cnt_t];
				if(a[i][j] == ans_num)
				{
					cout<<i+1<<" "<<j+1;
				}
				cnt_t++;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
