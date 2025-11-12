#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int b[200]={0},i,j,n,m,aaa,s=1;
	cin>>n>>m;
	bool h=1;
	for(i=1;i<=n*m;i++)
	cin>>b[i];
	aaa=b[1];
	sort(b+1,b+n*m+1);
	reverse(b+1,b+n*m+1);
	for(i=1;i<=m;i++)
	if(h==1)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=b[s];
			s++;
			if(a[i][j]==aaa){cout<<i<<' '<<j;break;}
		}
		h=0;
	}
	else if(h==0)
		 {
		 	for(j=n;j>=1;j--)
			{
				a[i][j]=b[s];
				s++;
				
				if(a[i][j]==aaa){cout<<i<<' '<<j;break;}
			}
			h=1;
		 }
	fclose(stdin);
	fclose(stdout);		
	return 0;	
}
