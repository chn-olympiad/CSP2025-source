#include<bits/stdc++.h>
using namespace std;
long long t,n,bj[4],ans,aa[100010][4];
struct sut
{
	long long a1,b1,c1,aid,bid,cid,sy;
}a[100010];
bool cmp(sut u,sut v)
{
	if (u.a1!=v.a1)
	{
		return u.a1>v.b1;
	}else if (u.a1==v.a1 && u.b1!=v.b1)
	{
		return u.b1>v.b1;
	}
	return u.c1>v.c1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (long long hh=1;hh<=t;hh++)
	{
		cin>>n;
		ans=0;
		long long a2=0,b2=0,c2=0;
		bj[1]=0;
		bj[2]=0;
		bj[3]=0;
		for (long long i=1;i<=n;i++)
		{
			cin>>aa[i][1]>>aa[i][2]>>aa[i][3];
			if (aa[i][1]>max(aa[i][2],aa[i][3]))
			{
				a[i].aid=1;
				a[i].a1=aa[i][1];
				if (aa[i][2]<aa[i][3])
				{
					a[i].bid=3;
					a[i].b1=aa[i][3];
					a[i].cid=2;
					a[i].c1=aa[i][2];
				}else
				{
					a[i].bid=2;
					a[i].b1=aa[i][2];
					a[i].cid=3;
					a[i].c1=aa[i][3];
				}
			}else if (aa[i][2]>max(aa[i][1],aa[i][3]))
			{
				a[i].aid=2;
				a[i].a1=aa[i][2];
				if (aa[i][1]<aa[i][3])
				{
					a[i].bid=3;
					a[i].b1=aa[i][3];
					a[i].cid=1;
					a[i].c1=aa[i][1];
				}else
				{
					a[i].bid=1;
					a[i].b1=aa[i][1];
					a[i].cid=3;
					a[i].c1=aa[i][3];
				}
			}else if (aa[i][3]>max(aa[i][1],aa[i][2]))
			{
				a[i].aid=3;
				a[i].a1=aa[i][3];
				if (aa[i][2]<aa[i][1])
				{
					a[i].bid=1;
					a[i].b1=aa[i][1];
					a[i].cid=2;
					a[i].c1=aa[i][2];
				}else
				{
					a[i].bid=2;
					a[i].b1=aa[i][2];
					a[i].cid=1;
					a[i].c1=aa[i][1];
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		bool flag=0;
		for (long long i=1;i<=n;i++)
		{
			flag=false;
			if (bj[1]+1<=n/2)
			{
				bj[1]++;
				ans+=a[i].a1;
				a[i].sy=1;
				flag=true;
			}else if (bj[1]+1>n/2 && bj[2]+1<=n/2)
			{
				bj[1]++;
				ans+=a[i].b1;
				a[i].sy=2;
			}else if (bj[1]+1>n/2 && bj[2]+1>n/2 && bj[3]+1<=n/2)
			{
				bj[3]++;
				ans+=a[i].c1;
				a[i].sy=3;
			}
			if (flag==true)
			{
				continue;
			}
			for (long long j=1;j<=i-1;j++)
			{
				long long j1,j2,j3,i1,i2,i3,num1,num2,num3;
				if (a[j].aid==1)
				{
					j1=1;
				}else if (a[j].aid==2)
				{
					j1=2;
				}else if (a[j].aid==3)
				{
					j1=3;
				}	
				if (a[j].bid==1)
				{
					j2=1;
				}else if (a[j].bid==2)
				{
					j2=2;
				}else if (a[j].bid==3)
				{
					j2=3;
				}	
				if (a[j].cid==1)
				{
					j3=1;
				}else if (a[j].cid==2)
				{
					j3=2;
				}else if (a[j].cid==3)
				{
					j3=3;
				}	
				if (a[i].aid==1)
				{
					i1=1;
				}else if (a[i].aid==2)
				{
					i1=2;
				}else if (a[i].aid==3)
				{
					i1=3;
				}	
				if (a[i].bid==1)
				{
					i2=1;
				}else if (a[i].bid==2)
				{
					i2=2;
				}else if (a[i].bid==3)
				{
					i2=3;
				}	
				if (a[i].cid==1)
				{
					i3=1;
				}else if (a[i].cid==2)
				{
					i3=2;
				}else if (a[i].cid==3)
				{
					i3=3;
				}	
				if (j1==1)
				{
					num1=a[j].a1;
				}else if (j1==2)
				{
					num1=a[j].b1;
				}else if (j1==3)
				{
					num1=a[j].c1;
				}
				if (i1==1)
				{
					num1-=a[i].a1;
				}else if (i1==2)
				{
					num1-=a[i].b1;
				}else if (i1==3)
				{
					num1-=a[i].c1;
				}	
				if (j2==1)
				{
					num2=a[j].a1;
				}else if (j2==2)
				{
					num2=a[j].b1;
				}else if (j2==3)
				{
					num2=a[j].c1;
				}
				if (i2==1)
				{
					num2-=a[i].a1;
				}else if (i2==2)
				{
					num2-=a[i].b1;
				}else if (i2==3)
				{
					num2-=a[i].c1;
				}
				if (j3==1)
				{
					num3=a[j].a1;
				}else if (j3==2)
				{
					num3=a[j].b1;
				}else if (j3==3)
				{
					num3=a[j].c1;
				}
				if (i3==1)
				{
					num3-=a[i].a1;
				}else if (i3==2)
				{
					num3-=a[i].b1;
				}else if (i3==3)
				{
					num3-=a[i].c1;
				}
				if (i==3)
				{
					cout<<num1<<" "<<num2<<" "<<num3;
				}
				if (a[j].sy==1 && bj[1]==n/2)
				{
					if (num2>num3 && num2>num1 && bj[2]<n/2)
					{
						ans-=num1;
						ans+=num2;
						a[i].sy=1;
						a[j].sy=2;
						bj[1]--;
						bj[2]++;
					}else if (num3>num2 && num3>num1 && bj[3]<n/2)
					{
						ans-=num1;
						ans+=num3;
						a[i].sy=1;
						a[j].sy=3;
						bj[1]--;
						bj[3]++;
					}
				}else if (a[j].sy==2 && bj[2]==n/2)
				{
					if (num1>num3 && num1>num2 && bj[1]<n/2)
					{
						ans-=num1;
						ans+=num2;
						a[i].sy=2;
						a[j].sy=1;
						bj[2]--;
						bj[1]++;
					}else if (num3>num1 && num3>num2 && bj[3]<n/2)
					{
						ans-=num2;
						ans+=num3;
						a[i].sy=2;
						a[j].sy=3;
						bj[2]--;
						bj[3]++;
					}
				}else if (a[j].sy==3 && bj[3]==n/2)
				{
					if (num1>num2 && num1>num3 && bj[1]<n/2)
					{
						ans-=num3;
						ans+=num1;
						a[i].sy=3;
						a[j].sy=1;
						bj[3]--;
						bj[1]++;
					}else if (num2>num1 && num2>num3 && bj[2]<n/2)
					{
						ans-=num3;
						ans+=num2;
						a[i].sy=3;
						a[j].sy=2;
						bj[3]--;
						bj[2]++;
					}
				}
			}
		}
		//0ans=0;
		for (long long i=1;i<=n;i++)
		{
			if (a[i].sy==1)
			{
				cout<<a[i].a1<<" ";
			}else if (a[i].sy==2)
			{
				cout<<a[i].b1<<" ";
			}else if (a[i].sy==3)
			{
				cout<<a[i].c1<<" ";
			}
		}
		//cout<<ans<<endl;
	}
	return 0;
} 
