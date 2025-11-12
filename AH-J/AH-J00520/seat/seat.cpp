#include<bits/stdc++.h>
using namespace std;
int n,m,grade[105],rg,nm,nn,mn,a;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=n*m;i++)
		cin>>grade[i];
	rg=grade[1];
	sort(grade+1,grade+1+nm,cmp);
	for(int i=1;i<=m;i++)
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				a++;
				if(grade[a]==rg)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		else
			for(int j=n;j>=1;j--)
			{
				a++;
				if(grade[a]==rg)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
	return 0;
}
