#include<bits/stdc++.h>
using namespace std;
struct windy
{
	int b1,b2,b3,l;
}w[114514];
int t,n,s1,s2,s3,sum,k[114514],num=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
	while(t--)
	{
		s1=0;
		s2=0;
		s3=0;
		sum=0;
		num=0;
		cin>>n;
		for(int z=1;z<=n;z++)
		{
			cin>>w[z].b1>>w[z].b2>>w[z].b3;
			if(w[z].b1>=w[z].b2)
			{
				if(w[z].b1>=w[z].b3)
				{
					w[z].l=1;
					s1++;
					sum+=w[z].b1;
				}
				else
				{
					w[z].l=3;
					s3++;
					sum+=w[z].b3;
				}
			}
			else
			{
				if(w[z].b2>=w[z].b3)
				{
					w[z].l=2;
					s2++;
					sum+=w[z].b2;
				}
				else
				{
					w[z].l=3;
					s3++;
					sum+=w[z].b3;
				}
			}
		}
			if(s1>n/2)
			{
				for(int z=1;z<=n;z++)
				{
					if(w[z].l==1)
					{
						num++;
						k[num]=min(w[z].b1-w[z].b2,w[z].b1-w[z].b3);
					}
				}
				sort(k+1,k+1+num);
				for(int z=1;z<=(s1-n/2);z++)
				{
					sum-=k[z];
				}
			}
			else if(s3>n/2)
			{
				for(int z=1;z<=n;z++)
				{
					if(w[z].l==3)
					{
						num++;
						k[num]=min(w[z].b3-w[z].b2,w[z].b3-w[z].b1);
					}
				}
				sort(k+1,k+1+num);
				for(int z=1;z<=(s3-n/2);z++)
				{
					sum-=k[z];
				}
			}
			else if(s2>n/2)
			{
				for(int z=1;z<=n;z++)
				{
					if(w[z].l==2)
					{
						num++;
						k[num]=min(w[z].b2-w[z].b1,w[z].b2-w[z].b3);
					}
				}
				sort(k+1,k+1+num);
				for(int z=1;z<=(s2-n/2);z++)
				{
					sum-=k[z];
				}
			}
			cout<<sum<<endl;
	}
	return 0;
}
