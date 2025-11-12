#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[n*m],t,b,s[m][n];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	a[1]=t;
	sort(a+1,a+1+n*m,cmp);
	b=n*m;
	while(a[b]!=t)
	{
		b--;
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
		{s[i][j]=a[i*j];
		if(i*j==b){
		cout<<i<<" "<<j;
		break;
		}
		}
}
	return 0;
}
