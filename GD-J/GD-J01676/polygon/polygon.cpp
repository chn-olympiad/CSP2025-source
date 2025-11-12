#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10086],as=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]) cout<<1;
		else cout<<0;
	}
	else if(n==4)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]) as++;
		if(a[1]+a[2]>a[4]&&a[1]+a[4]>a[2]&&a[4]+a[2]>a[1]) as++;
		if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[3]+a[4]>a[1]) as++;
		if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[3]+a[2]>a[4]) as++;
		if(a[1]+a[2]+a[3]+a[4]>2*(max(a[1],max(a[2],max(a[3],a[4]))))) as++;
		cout<<as;
	}
	else if(n==5)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]) as++;
		if(a[1]+a[2]>a[4]&&a[1]+a[4]>a[2]&&a[4]+a[2]>a[1]) as++;
		if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[3]+a[4]>a[1]) as++;
		if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[3]+a[2]>a[4]) as++;
		if(a[1]+a[2]>a[5]&&a[1]+a[5]>a[2]&&a[5]+a[2]>a[1]) as++;
		if(a[1]+a[5]>a[3]&&a[1]+a[3]>a[5]&&a[3]+a[5]>a[1]) as++;
		if(a[1]+a[4]>a[5]&&a[1]+a[5]>a[4]&&a[5]+a[4]>a[1]) as++;
		if(a[5]+a[2]>a[3]&&a[5]+a[3]>a[2]&&a[3]+a[2]>a[5]) as++;
		if(a[5]+a[2]>a[4]&&a[5]+a[4]>a[2]&&a[4]+a[2]>a[5]) as++;
		if(a[5]+a[4]>a[3]&&a[5]+a[3]>a[4]&&a[3]+a[4]>a[5]) as++;
		if(a[1]+a[2]+a[3]+a[4]>2*(max(a[1],max(a[2],max(a[3],a[4]))))) as++;
		if(a[1]+a[2]+a[3]+a[5]>2*(max(a[1],max(a[2],max(a[3],a[5]))))) as++;
		if(a[1]+a[2]+a[5]+a[4]>2*(max(a[1],max(a[2],max(a[5],a[4]))))) as++;
		if(a[1]+a[5]+a[3]+a[4]>2*(max(a[1],max(a[5],max(a[3],a[4]))))) as++;
		if(a[5]+a[2]+a[3]+a[4]>2*(max(a[5],max(a[2],max(a[3],a[4]))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*(max(a[1],max(a[2],max(a[3],max(a[4],a[5])))))) as++;
		cout<<as;
	}
	else if(n==6)
	{
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int k=j+1;k<=6;k++)
				{
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) as++;
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int k=j+1;k<=5;k++)
				{
					for(int l=j+1;l<=6;l++)
					{
						if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) as++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*(max(a[1],max(a[2],max(a[3],max(a[4],a[5])))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>2*(max(a[1],max(a[2],max(a[3],max(a[4],a[6])))))) as++;
		if(a[1]+a[2]+a[3]+a[6]+a[5]>2*(max(a[1],max(a[2],max(a[3],max(a[6],a[5])))))) as++;
		if(a[1]+a[2]+a[6]+a[4]+a[5]>2*(max(a[1],max(a[2],max(a[6],max(a[4],a[5])))))) as++;
		if(a[1]+a[6]+a[3]+a[4]+a[5]>2*(max(a[1],max(a[6],max(a[3],max(a[4],a[5])))))) as++;
		if(a[6]+a[2]+a[3]+a[4]+a[5]>2*(max(a[6],max(a[2],max(a[3],max(a[4],a[5])))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6]))))))) as++;
		cout<<as;
	}
	else if(n==7)
	{
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				for(int k=j+1;k<=7;k++)
				{
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) as++;
				}
			}
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int k=j+1;k<=6;k++)
				{
					for(int l=k+1;l<=7;l++)
					{
						if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) as++;
					}
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int k=j+1;k<=5;k++)
				{
					for(int l=k+1;l<=6;l++)
					{
						for(int m=l+1;m<=7;m++) if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))) as++;
						
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6]))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[7]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[7]))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[7]+a[6]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[7],a[6]))))))) as++;
		if(a[1]+a[2]+a[3]+a[7]+a[5]+a[6]>2*(max(a[1],max(a[2],max(a[3],max(a[7],max(a[5],a[6]))))))) as++;
		if(a[1]+a[2]+a[7]+a[4]+a[5]+a[6]>2*(max(a[1],max(a[2],max(a[7],max(a[4],max(a[5],a[6]))))))) as++;
		if(a[1]+a[7]+a[3]+a[4]+a[5]+a[6]>2*(max(a[1],max(a[7],max(a[3],max(a[4],max(a[5],a[6]))))))) as++;
		if(a[7]+a[2]+a[3]+a[4]+a[5]+a[6]>2*(max(a[7],max(a[2],max(a[3],max(a[4],max(a[5],a[6]))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],a[7])))))))) as++;
		cout<<as;
	}
	else if(n==8)
	{
		for(int i=1;i<=6;i++)
		{
			for(int j=i+1;j<=7;j++)
			{
				for(int k=j+1;k<=8;k++)
				{
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) as++;
				}
			}
		}
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				for(int k=j+1;k<=7;k++)
				{
					for(int l=k+1;l<=8;l++)
					{
						if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) as++;
					}
				}
			}
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int k=j+1;k<=6;k++)
				{
					for(int l=k+1;l<=7;l++)
					{
						for(int m=l+1;m<=8;m++) if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))) as++;
						
					}
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int k=j+1;k<=5;k++)
				{
					for(int l=k+1;l<=6;l++)
					{
						for(int m=l+1;m<=7;m++) for(int o=m+1;o<=8;o++) if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o])))))) as++;
						
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],a[7])))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[8]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],a[8])))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[8]+a[7]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[8],a[7])))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[8]+a[6]+a[7]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[8],max(a[6],a[7])))))))) as++;
		if(a[1]+a[2]+a[3]+a[8]+a[5]+a[6]+a[7]>2*(max(a[1],max(a[2],max(a[3],max(a[8],max(a[5],max(a[6],a[7])))))))) as++;
		if(a[1]+a[2]+a[8]+a[4]+a[5]+a[6]+a[7]>2*(max(a[1],max(a[2],max(a[8],max(a[4],max(a[5],max(a[6],a[7])))))))) as++;
		if(a[1]+a[8]+a[3]+a[4]+a[5]+a[6]+a[7]>2*(max(a[1],max(a[8],max(a[3],max(a[4],max(a[5],max(a[6],a[7])))))))) as++;
		if(a[8]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*(max(a[8],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],a[7])))))))) as++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*(max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],a[8]))))))))) as++;
		cout<<as;
	}
	else cout<<0;
	return 0;
}
