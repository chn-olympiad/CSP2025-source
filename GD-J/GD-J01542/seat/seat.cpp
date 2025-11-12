#include<iostream>
#include<algorithm>
using namespace std;
int mp[15][15];
int a[1005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()//Ô¤¼Æ80~100pts 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>a[1];
	r = a[1];
	for(int i = 2;i <= n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	int k = 1;
	int ansx = 0,ansy;
	for(int j = 1;j <= m;j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				mp[i][j] = a[k];
				if(a[k] == r)
				{
					ansx = j,ansy = i;
					//cout<<r<<' '<<a[k]<<' '<<k<<endl;
				}
				k++;
			}
		}
		else
		{
			for(int i = n;i >= 1;i--)
			{
				mp[i][j] = a[k];
				if(a[k] == r)
				{
					ansx = j,ansy = i;
				}
				k++;
			}
		}
	}
	cout<<ansx<<' '<<ansy;
	return 0;	
} 
