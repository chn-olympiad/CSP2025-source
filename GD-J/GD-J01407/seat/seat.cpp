#include<bits/stdc++.h>
using namespace std;

int n,m,x,j=1,y,jige,yu,h=1,l=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<=n*m-1;i++)
	{
		scanf("%d",&y);
		if(y>x)	j++;
	}
	
	for(int i=1;i<j;i++)
	{
		if(l%2==1)
		{
			h++;
			if(h>n)
			{
				l++;
				h=n;
			}
		}else
		{
			h--;
			if(h==0)
			{
				l++;
				h=1;
			}
		}
	}
	
	cout<<l<<' '<<h<<endl;	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
//#Shang4Shan3Ruo6Shui4
