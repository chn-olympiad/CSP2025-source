#include<bits/stdc++.h>
using namespace std;
int t;
struct edge
{
	int w1,w2,w3;
}a[100005];
int aa[100005];
int ansn[100];
int dp[100005];
int n;
#define ls p<<1
#define rs p<<1|1
struct node
{
	int lazy,sum;
}e[400006];
void pushdown(int l,int r,int p)
{
	int &lazy=e[p].lazy;
	e[ls].lazy+=lazy;
	e[rs].lazy+=lazy;
	int mid=(l+r)>>1;
	e[ls].sum+=lazy*(mid-l+1);
	e[rs].sum+=lazy*(r-mid);
	lazy=0;
	return;
}
void update(int l,int r,int x,int y,int val,int p)
{
	if(x<=l||y<=r)
	{
		e[p].sum=l-r+1;
		e[p].lazy=0;
		return;
	}
	if(e[p].lazy!=0)
	{
		pushdown(l,r,p);
	}
	int mid=(l+r)>>1;
	if(l<=mid)
	{
		update(1,n,l,mid,val,ls);
	}
	if(r>mid)
	{
		update(1,n,mid+1,r,val,rs);
	}
	e[p].sum=e[ls].sum+e[rs].sum;
}
int query(int l,int r,int x,int y,int p)
{
	if(x<=l||y<=r)
	{
		return e[p].sum;
	}
	if(e[p].lazy!=0)
	{
		pushdown(l,r,p);
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(l<=mid)
	{
		ans+=query(1,n,l,mid,ls);
	}
	if(r>mid)
	{
		ans+=query(1,n,mid+1,r,rs);
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int cnt1=0,cnt2=0,cnt3=0;
		int ans=0;
		int anss=0;
		scanf("%d",&n);
		if(n==2)
		{
			int a1,b,c,d,e,f;
			int i,j,k,l,p,o;
			scanf("%d%d%d%d%d%d",&a1,&b,&c,&d,&e,&f);
			i=a1+e;
			j=a1+f;
			k=b+d;
			l=b+f;
			p=c+d;
			o=c+e;
			printf("%d",max({i,j,k,l,p,o}));
		}
		else if(n==4)
		{
			int ans12=0;
			int b[20];
			for(int i=1;i<=12;i++)
			{
				scanf("%d",&b[i]);
			}
			ansn[1]=b[1]+b[4]+b[8]+b[11];
			ansn[2]=b[1]+b[4]+b[8]+b[12];
			ansn[3]=b[1]+b[4]+b[9]+b[11];
			ansn[4]=b[1]+b[4]+b[9]+b[12];
			ansn[6]=b[1]+b[5]+b[7]+b[11];
			ansn[7]=b[1]+b[5]+b[7]+b[12];
			ansn[8]=b[1]+b[5]+b[8]+b[10];
			ansn[9]=b[1]+b[5]+b[8]+b[12];
			ansn[10]=b[1]+b[6]+b[7]+b[10];
			ansn[11]=b[1]+b[6]+b[7]+b[11];
			ansn[12]=b[1]+b[6]+b[7]+b[12];
			ansn[13]=b[1]+b[6]+b[8]+b[10];
			ansn[14]=b[1]+b[6]+b[8]+b[11];
			ansn[15]=b[1]+b[6]+b[8]+b[12];
			ansn[16]=b[2]+b[6]+b[7]+b[11];
			ansn[17]=b[2]+b[6]+b[7]+b[12];
			ansn[18]=b[2]+b[4]+b[7]+b[11];
			ansn[19]=b[2]+b[4]+b[7]+b[12];
			ansn[20]=b[2]+b[4]+b[8]+b[10];
			ansn[21]=b[2]+b[4]+b[8]+b[12];
			ansn[22]=b[2]+b[4]+b[9]+b[10];
			ansn[23]=b[2]+b[4]+b[9]+b[12];
			ansn[24]=b[2]+b[5]+b[7]+b[10];
			ansn[25]=b[2]+b[5]+b[7]+b[12];
			ansn[26]=b[2]+b[5]+b[9]+b[10];
			ansn[27]=b[2]+b[5]+b[9]+b[12];
			ansn[28]=b[2]+b[6]+b[7]+b[10];
			ansn[29]=b[2]+b[6]+b[7]+b[11];
			ansn[30]=b[2]+b[6]+b[7]+b[12];
			ansn[31]=b[2]+b[6]+b[8]+b[10];
			ansn[32]=b[2]+b[6]+b[8]+b[12];
			ansn[33]=b[3]+b[4]+b[7]+b[11];
			ansn[34]=b[3]+b[4]+b[8]+b[10];
			ansn[35]=b[3]+b[4]+b[8]+b[11];
			ansn[36]=b[3]+b[4]+b[8]+b[12];
			ansn[37]=b[3]+b[4]+b[9]+b[10];
			ansn[38]=b[3]+b[4]+b[9]+b[11];
			ansn[39]=b[3]+b[5]+b[7]+b[10];
			ansn[40]=b[3]+b[5]+b[7]+b[11];
			ansn[41]=b[3]+b[5]+b[7]+b[12];
			ansn[42]=b[3]+b[6]+b[7]+b[10];
			ansn[43]=b[3]+b[6]+b[7]+b[11];
			ansn[44]=b[3]+b[6]+b[8]+b[10];
			ansn[45]=b[3]+b[6]+b[8]+b[11];
			for(int i=1;i<=50;i++)
			{
				ans12=max(ansn[i],ans12);
			}
			printf("%d\n",ans12);
		}
		else
		{
			int cnt22=0,cnt33=0;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&aa[i],&a[i].w2,&a[i].w3);
				a[i].w1=aa[i];
				if(a[i].w2==0)
				{
					cnt22++;
				}
				if(a[i].w3==0)
				{
					cnt33++;
				}
			}
			if(cnt22==n&&cnt33==n)
			{
				sort(aa+1,aa+n+1);
				for(int i=n;i>=n/2+1;i--)
				{
					ans+=aa[i];
				}
				// for(int i=n;i>=n/2+1;i--)
				// {
				// 	printf("a[]: %d\n",aa[i]);
				// }
				printf("%d\n",ans);
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=3;j++)
					{
						for(int k=1;k<=n;k++)
						{
							for(int l=1;l<=3;l++)
							{
								if(j==1)
								{
									cnt1++;
									if(k!=i)
									{
										if(l==1&&cnt1<=n/2)
										{
											cnt1++;
											ans+=a[k].w1;
										}
										else if(l==2&&cnt2<=n/2)
										{
											cnt2++;
											ans+=a[k].w2;
										}
										else if(l==3&&cnt3<=n/2)
										{
											cnt3++;
											ans+=a[k].w3;
										}
									}
								}
								if(j==2)
								{
									cnt2++;
									if(k!=i)
									{
										if(l==1&&cnt1<=n/2)
										{
											cnt1++;
											ans+=a[k].w1;
										}
										else if(l==2&&cnt2<=n/2)
										{
											cnt2++;
											ans+=a[k].w2;
										}
										else if(l==3&&cnt3<=n/2)
										{
											cnt3++;
											ans+=a[k].w3;
										}
									}
								}
								if(j==1)
								{
									cnt3++;
									if(k!=i)
									{
										if(l==1&&cnt1<=n/2)
										{
											cnt1++;
											ans+=a[k].w1;
										}
										else if(l==2&&cnt2<=n/2)
										{
											cnt2++;
											ans+=a[k].w2;
										}
										else if(l==3&&cnt3<=n/2)
										{
											cnt3++;
											ans+=a[k].w3;
										}
									}
								}
							}
						}
						
					}
				}
				printf("%d\n",ans);
			}
		}
		// for(int i=1;i<=n;i++)
		// {
		// 	scanf("%d%d%d",&a[i].w1,&a[i].w2,&a[i].w3);
		// }
		// for(int i=1;i<=n;i++)
		// {
		// 	ans=0;
		// 	for(int j=1;j<=n;j++)
		// 	{
		// 		for(int k=1;k<=3;k++)
		// 		{
		// 			if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
		// 			{
		// 				ans+=a[i].w1;
		// 			}
		// 		}
		// 		anss=max(anss,ans);
		// 	}
		//update(1,n,j,k,ans,1);
		// }
		//ans=query(1,n,j,k,1);
		// printf("%d\n",anss);
	}
	return 0;
}