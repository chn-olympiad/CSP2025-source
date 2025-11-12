#include <bits/stdc++.h>
using namespace std;
int n,m;int a[110];int t,te;int tx,ty;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++)
	{
		cin>>a[i];
		if(i==1)
		{
			t=i;
			te=a[1];
		}
		if(a[i]>te)
		{
			t++;
		}
	}
	if(n==1&&m==1)
	{
		cout<<a[1];
		return 0;
	} 
	sort(a+1,a+n+1,cmp);
	if(t%n==0)
	{
		tx=t/n;
	}
	else
	{
		tx=(t/n)+1;
	}
	ty=((t-1)%n)+1;
	if(tx%2==0)
	{
		ty=(n-ty+1);
	}
	cout<<tx<<" "<<ty;
	return 0;
} 
