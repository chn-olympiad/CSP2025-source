#include<bits/stdc++.h>
using namespace std;
int a[11][11],t[102],sum,cz;
int n,m;
int x,y,xx,xy;
int wx[3]={0,0,1};
int wy[3]={1,-1,0};
bool cmp(int x,int y)
{
	return x>y;
}
int go(int weew)
{
	for(int j=0;j<3;j++)
		{
			xx+=wx[j];
			xy+=wy[j];
			if(xx<n&&xy<m&&xy>=0&&a[xx][xy]==0)
			{
				a[xx][xy]=t[weew];
				x=xx;
				y=xy;
				return 0;
			}else
			{
				xx=x;
				xy=y;
			}
		}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>t[sum];
			sum++;
		}
	}cz=t[0];
	sort(t,t+sum,cmp);
	a[0][0]=t[0];
	for(int i=1;i<sum;i++)
	{
		if(t[i]!=cz)go(i);
		else
		{
			go(i);
			break;
		 } 
	}
	cout<<xx+1<<" "<<xy+1;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

