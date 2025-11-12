#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110]={0};
int cmp(int i,int j){return i>j;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1,k=1;j<=m;j+=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[k]!=x)
				k++;
			else
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
		j++;
		for(int i=n;i>=1;i--)
		{
			if(a[k]!=x)
				k++;
			else
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
