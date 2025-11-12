#include<bits/stdc++.h>
#define int  long long
using namespace std;
int n,m;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int y=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	int x=1;
	int i=1,j=1;
	bool d=0;
	while(i*j<n*m)
	{
		if(a[x]==y)break;
		else if(d==0&&i==n)
		{
			d=1;
			j++;
			x++;
		}
		else if(d==1&&i==1)
		{
			d=0;
			j++;
			x++;
		}
		else if(!d)
		{
			i++;
			x++;
		}
		else
		{
			i--;
			x++;
		}
	}
	cout << j << " "<< i;
	return 0;
}//我是神人 
