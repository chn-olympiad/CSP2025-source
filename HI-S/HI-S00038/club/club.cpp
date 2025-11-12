# include <bits/stdc++.h>
using namespace std;
int t,n;
bool f,bj;
struct node {
	int x,y,z,mm;
}a[100005];
//int aa[100005];
//int bb[100005];
//int cc[100005];
bool cmpA(node e,node f)
{
	return e.x>f.x;
}
bool cmpB(node e,node f)
{
	return e.y>f.y;
}
bool cmpC(node e,node f)
{
	return e.z>f.z;
}
void A()
{
	int sum=0;
	sort(a+1,a+1+n,cmpA);
	for (int i=1;i<=n/2;i++)
	{
		sum += a[i].x;
	}
	printf("%d\n",sum);
}
void B()
{
	int suma1=0,suma2=0,sumb1=0,sumb2=0;
	sort(a+1,a+1+n,cmpA);
	for (int i=1;i<=n/2;i++)
	{
		suma1+=a[i].x;
	}
	for (int i=n/2+1;i<=n;i++)
	{
		suma2+=a[i].y;
	}
	sort(a+1,a+1+n,cmpB);
	for (int i=1;i<=n/2;i++)
	{
		sumb1+=a[i].y;
	}
	for (int i=n/2+1;i<=n;i++)
	{
		sumb2+=a[i].x;
	}
	printf("%d\n",max(suma1+suma2,sumb1+sumb2));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		f=0;
		bj=0;
		scanf("%d",&n);
		for (int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].z);
			if (a[j].y!=0 || a[j].z!=0)  f=1;
			if (a[j].z!=0)  bj=1;
		}
		if (n==2)
		{
			printf("%d\n",max(a[1].x+a[2].y,max(a[1].x+a[2].z,max(a[1].y+a[2].x,max(a[1].y+a[2].z,max(a[1].z+a[2].x,max(a[1].z+a[2].y,max(a[2].x+a[1].y,max(a[2].x+a[1].z,max(a[2].y+a[1].x,max(a[2].y+a[1].z,max(a[2].z+a[1].x,a[2].z+a[1].y))))))))))));
		}else if (f==0)
		{
			A();
		}else if (bj==0)
		{
			B();
		}else if (f!=0 && bj!=0 && n!=2)
		{
			int cnt1=0,cnt2=0,cnt3=0;
			for (int k=1;k<=n;k++)
			{
				a[k].mm = max(a[k].x,max(a[k].y,a[k].z));
				if (a[k].mm==a[k].x)
				{
					a[k].mm=1;
					cnt1 ++;
				}
				else if (a[k].mm==a[k].y)
				{
					a[k].mm=2;
					cnt2 ++;
				}
				else if (a[k].mm==a[k].z)  
				{
					a[k].mm=3;
					cnt3 ++;
				}
			}
			if (cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2)
			{
				int summ=0;
				for (int k=1;k<=n;k++)
			    {
			    	if (a[k].mm==1)
			    	{
			    		summ +=a[k].x;
					}
					if (a[k].mm==2)
			    	{
			    		summ +=a[k].y;
					}
					if (a[k].mm==3)
			    	{
			    		summ +=a[k].z;
					}
				}
				printf("%d\n",summ);
			}
			else
			{
				int summ=0;
				if (cnt1>n/2)
				{
					cnt1=1;
					sort(a+1,a+1+n,cmpA);
					for (int l=1;l<=n;l++)
					{
						if (a[l].mm==1 && cnt1<=n/2)
						{
							summ+=a[l].x;
							cnt1 ++;
						}
						else if (a[l].mm==2)
						{
							summ +=a[l].y;
						}
						else if (a[l].mm==3)
						{
							summ +=a[l].z;
						}else if (a[l].mm==1 && cnt1>n/2)
						{
							summ+=max(a[l].y,a[l].z);
						}
					}
				}
				else if (cnt2>n/2)
				{
					cnt2=0;
					sort(a+1,a+1+n,cmpB);
					for (int l=1;l<=n;l++)
					{
						if (a[l].mm==2 && cnt2<=n/2)
						{
							summ+=a[l].y;
							cnt2 ++;
						}	
						else if (a[l].mm==1)
						{
							summ +=a[l].x;
						}
						else if (a[l].mm==3)
						{
							summ +=a[l].z;
						}else if (a[l].mm==2 && cnt2>n/2)
						{
							summ+=max(a[l].x,a[l].z);
						}
					}
				}
				else if (cnt3>n/2)
				{
					cnt3=0;
					sort(a+1,a+1+n,cmpC);
					for (int l=1;l<=n;l++)
					{
						if (a[l].mm==3 && cnt3<=n/2)
						{
							summ+=a[l].z;
							cnt3 ++;
						}
						else if (a[l].mm==2)
						{
							summ +=a[l].y;
						}
						else if (a[l].mm==1)
						{
							summ +=a[l].x;
						}else if (a[l].mm==3 && cnt3>n/2)
						{
							summ+=max(a[l].y,a[l].x);
						}
					}
				}
				printf("%d\n",summ);
//				cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2
			}
		}
	}
	return 0;
}
