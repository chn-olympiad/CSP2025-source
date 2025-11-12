#include<bits/stdc++.h>
using namespace std;
int n,m,x,r;
int a[110],mapp[20][20];
bool cmp(int x,int y){
	if (x>y) return true;
	return false;
}
int main(){
    freopen("seat.in","r",stdin);	
    freopen("seat.out","w",stdout);		
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for (int i=2;i<=m*n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (i%2!=0)
		{
			for (int j=1;j<=n;j++)
			{
				x++;
				mapp[j][i]=a[x];
			}
		}
		if (i%2==0)
		{
			for (int j=n;j>=1;j--)
			{
				x++;
				mapp[j][i]=a[x];
			}	
		}
	}
/*	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cout<<mapp[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (mapp[j][i]==r) 
			{
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
