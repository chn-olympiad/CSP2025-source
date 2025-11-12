#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int cnt=0;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int xr;
	cin>>xr;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==0&&j==1){
				break;
			}
			else{
				int tp;
				cin>>tp;
				if(tp>xr)
				{
					cnt++;
				}
			}
		}
	}
	int lei=cnt/n+1;
	int hang;
	if(lei%2==1)
	{
		hang=cnt%n+1;
	} 
	else
	{
		hang=n-(cnt%n);
	}
	cout<<lei<<" "<<hang;
	return 0;
 } 
