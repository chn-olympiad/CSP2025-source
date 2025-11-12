#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,k[5]={0},my[100005][3],zuida=0,flag,xm[2],myd=0,change=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			for(int k=0;k<3;k++)
			{
				cin>>my[j][k];
			}
		}
		if(k[i]==2)
		{
			for(int h=0;h<k[i];h++)
			{
				for(int l=0;l<3;l++)
				{
					flag=zuida;
					zuida=max(zuida,my[h][l]);
					if(zuida-flag)
					{
						xm[0]=h;
						xm[1]=l;
					}
				}
			}
			myd+=zuida;
			zuida=0;
			my[xm[0]][xm[1]]=0;
			for(int h=0;h<k[i];h++)
			{
				for(int l=0;l<3;l++)
				{
					if((h!=xm[0])&&(l!=xm[1]))
					{
						zuida=max(zuida,my[h][l]);
					}
				}
			}
			myd+=zuida;
			cout<<myd<<endl;
			myd=0;
			continue;
		}
		for(int x=0;x<k[i];x++)
		{
			for(int y=0;y<k[i];y++)
			{
				change=max(my[y][0],my[y+1][0]);
				if(my[y][0]!=change)
				{
					my[y+1][0]=my[y][0];
					my[y][0]=change;
				}
				change=0;
			}
		} 
		while(sum<k[i]/2)
		{
			myd+=my[sum][0];
			sum++;
		}
		cout<<myd<<endl;
		myd=0;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
