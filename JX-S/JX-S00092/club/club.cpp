#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int t,n,s[3][N],sum1[N],sum2[N],sum3[N],cnt1,cnt2,cnt3;
bool flag1,flag2,flag3;
bool cmp1(int a,int b){return s[0][a]<s[0][b];}
bool cmp2(int a,int b){return s[1][a]<s[1][b];}
bool cmp3(int a,int b){return s[2][a]<s[2][b];}
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);	
   scanf("%d",&t);
   for(int k=1;k<=t;k++)
   {
	   memset(s,0,sizeof(s));
	   memset(sum1,0,sizeof(sum1));
	   memset(sum2,0,sizeof(sum2));
	   memset(sum2,0,sizeof(sum3));
	   cnt1=cnt2=cnt3=0;
	   flag1=flag2=flag3=0;
	   int ans=0;
	   scanf("%d",&n);
	   int x=n/2;
	   for(int i=1;i<=n;i++)
	   {
		   scanf("%d%d%d",&s[0][i],&s[1][i],&s[2][i]);   
	   }
	   for(int i=1;i<=n;i++)
	   {
		    if(s[0][i]>=s[1][i]&&s[0][i]>=s[2][i])
		    {
				if(cnt1+1>x)
				{
					if(!flag1)
					{
						sort(sum1+1,sum1+cnt1+1,cmp1);
						flag1=1;
					}
					int v=sum1[1];
					if(s[0][v]+max(s[1][i],s[2][i])>s[0][i]+max(s[1][v],s[2][v]))
					{
						if(s[1][i]>=s[2][i]&&cnt2<x)
						{
							sum2[++cnt2]=i;
						}
						else
						{
							sum3[++cnt3]=i;
						}
					}
		            else
		            {
						if(s[1][v]>=s[2][v]&&cnt2<x)
						{
							sum2[++cnt2]=v;
						}
						else
						{
							sum3[++cnt3]=v;
						}
					   	int x=cnt1;
					   	for(int j=2;j<=cnt1;j++)if(s[0][j]>s[0][i]){x=j-1;break;}
						for(int j=x;j>=2;j--)sum1[j-1]=sum1[j];
						sum1[x]=i;
						
					} 
				}
				else sum1[++cnt1]=i;
			}
		    else if(s[1][i]>=s[0][i]&&s[1][i]>=s[2][i])
		    {
				if(cnt2+1>x)
				{
					if(!flag2)
					{
						sort(sum2+1,sum2+cnt2+1,cmp2);
						flag2=1;
					}
					int v=sum2[1];
					if(s[1][v]+max(s[0][i],s[2][i])>s[1][i]+max(s[0][v],s[2][v]))
					{
						if(s[0][i]>=s[2][i]&&cnt1<x)
						{
							sum1[++cnt1]=i;
						}
						else
						{
							sum3[++cnt3]=i;
						}
					}
		            else
		            {
						if(s[0][v]>=s[2][v]&&cnt1<x)
						{
							sum1[++cnt1]=v;
						}
						else
						{
							sum3[++cnt3]=v;
						}
					   	int x=cnt2;
					   	for(int j=2;j<=cnt2;j++)if(s[1][j]>s[1][i]){x=j-1;break;}
						for(int j=x;j>=2;j--)sum2[j-1]=sum2[j];
						sum2[x]=i;
					} 
				}
				else sum2[++cnt2]=i;
			}
		    else if(s[2][i]>=s[1][i]&&s[2][i]>=s[0][i])
		    {
				if(cnt3+1>x)
				{
					if(!flag3)
					{
						sort(sum3+1,sum3+cnt3+1,cmp3);
						flag3=0;
				    }
					int v=sum3[1];
					if(s[2][v]+max(s[1][i],s[0][i])>s[2][i]+max(s[1][v],s[0][v]))
					{
						if(s[1][i]>=s[0][i]&&cnt2<x)
						{
							sum2[++cnt2]=i;
						}
						else
						{
							sum1[++cnt1]=i;
						}
					} 
		            else
		            {
						if(s[1][v]>=s[0][v]&&cnt2<x)
						{
							sum2[++cnt2]=v;
						}
						else
						{
							sum1[++cnt1]=v;
						}
					   	int x=cnt3;
					   	for(int j=2;j<=cnt3;j++)if(s[2][j]>s[2][i]){x=j-1;break;}
						for(int j=x;j>=2;j--)sum3[j-1]=sum3[j];
						sum3[x]=i;
					} 
				}
				else sum3[++cnt3]=i;
			}    
	   }
	   for(int i=1;i<=cnt1;i++)ans+=s[0][sum1[i]];
	   for(int i=1;i<=cnt2;i++)ans+=s[1][sum2[i]];
	   for(int i=1;i<=cnt3;i++)ans+=s[2][sum3[i]];
	   printf("%d\n",ans);
   }
   return 0;
}
