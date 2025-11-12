#include "bits/stdc++.h" 
using namespace std;
int a[110][110],b[110],n,m,c,s,k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n*m;i++) cin>>b[i];
	c=b[1];
	/*cout<<"b:\n";for(i=1;i<=n*m;i++) cout<<b[i]<<" ";cout<<endl;*/
	sort(b+1,b+(n*m)+1,cmp);//½µÐò 
	for(j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(i=1;i<=n;i++)
			{
				a[i][j]=b[++k];
			}
		}
		if(j%2==0)
		{
			for(i=n;i>=1;i--)
			{
				a[i][j]=b[++k];
			}
		}

	}/*
	cout<<"a:\n";
	for(i=1;i<=n;i++)
	{for(j=1;j<=m;j++) cout<<a[i][j]<<" ";cout<<endl;
	 }*/ 
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(a[i][j]==c) cout<<j<<" "<<i;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
