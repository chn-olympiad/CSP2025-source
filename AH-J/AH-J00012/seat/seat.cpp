#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[110],n,m,h,x=1,y=1;
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	h=a[0];
	sort(a,a+m*n);
	for(int i=m*n-1;i>=0;i--)
	{
		if(a[i]==h)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if(x%2==1)
		{
			if(y<m)
			{
				y++;
			}else{
				x++;
			}
		}else
		{
			if(y>1)
			{
				y--;
			}else{
				x++;
			}
		}
		
	}
	return 0;
}
