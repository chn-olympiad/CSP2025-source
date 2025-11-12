#include <bits/stdc++.h>
using namespace std;
int T,n,a,b,c,need,sum,check,group;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int list[100001][4],num[100001]; 
	for(int i=1;i<=T;i++)
	{
		cin>>n; a=0,b=0,c=0,sum=0,check=0; 
		for(int j=1;j<=n;j++) 
		{
			cin>>list[j][1]>>list[j][2]>>list[j][3];
			if(list[j][1]>=list[j][2]&&list[j][1]>=list[j][3])
			{
				a++; sum+=list[j][1];
			}
			else if(list[j][2]>=list[j][1]&&list[j][2]>=list[j][3])
			{
				b++; sum+=list[j][2];
			}
			else if(list[j][3]>=list[j][2]&&list[j][3]>=list[j][1])
			{
				c++; sum+=list[j][3];
			}
		}
		if(a>=b&&a>=c) group=1;
		else if(b>=a&&b>=c) group=2;
		else group=3; 
		if(a>(n/2)||b>(n/2)||c>(n/2))
		{
			for(int j=1;j<=n;j++)
			{
				if(group==1)
				{
					need=a-(n/2);
					if(list[j][1]>=list[j][2]&&list[j][1]>=list[j][3])
					{
						check++;
						num[check]=list[j][1]-max(list[j][2],list[j][3]);
					}
				}
				else if(group==2)
				{
					need=b-(n/2);
					if(list[j][2]>=list[j][1]&&list[j][2]>=list[j][3])
					{
						check++;
						num[check]=list[j][2]-max(list[j][1],list[j][3]);
					}
				}
				else
				{
					need=c-(n/2);
					if(list[j][3]>=list[j][2]&&list[j][3]>=list[j][1])
					{
						check++;
						num[check]=list[j][3]-max(list[j][2],list[j][1]);
					}
				}
			}
			sort(num+1,num+need+(n/2)+1);
			for(int j=1;j<=need;j++) sum-=num[j];
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
