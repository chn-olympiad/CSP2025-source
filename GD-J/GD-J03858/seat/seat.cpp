#include <bits/stdc++.h>
using namespace std;
struct ff{
	int num,t;
};
ff a[110];
int dx[3]={0,1,0};
int dy[3]={1,0,-1};
int dk[5]={0,1,2,1,0};

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].t=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i].num<a[j].num) {
				int x=a[i].t;
				a[i].t=a[j].t;
				a[j].t=x;
			}
		}
	}
	int w=a[1].t-1;
	int x=1,y=1,d=0,k=1;
	while(w--)
	{
		x+=dx[d];y+=dy[d];
		if((x!=1&&y==1)||(y==m)){
			d=dk[k++];if(k==4) k=0;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}

