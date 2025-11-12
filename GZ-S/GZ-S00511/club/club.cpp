//绥阳县绥阳中学 黎煜 GZ-S00511 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#define maxn 11451419
using namespace std;
struct cy
{
	int m1,m2,m3;
	bool sy;
	int Ma;
	int Mx;
	int Mc;
	int mn=0;
}cy[maxn];
int main()
{
	freopen("stdin","w",club.in);
	freopen("stdout","r",club.out);
	int mnn=0,n,t,ans=0,Maa=0,Mxx=0,Mcc=0;
	int a[4],bn[10];
	int mi,mj;
	for(int i=1;i<=3;i++)
		a[i]=0;
	cin>>t;
	int beat[t+1];
	beat[1]=0;
	int vb[3];
	for(int v=1;v<=t;v++)
	{
		cin>>n;
		mnn=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&cy[i].m1,&cy[i].m2,&cy[i].m3);
			cy[i].Ma=max(cy[i].m1,max(cy[i].m2,cy[i].m3));
			cy[i].Mc=min(cy[i].m1,min(cy[i].m2,cy[i].m3));
			cy[i].Mx=cy[i].m1+cy[i].m2+cy[i].m3-cy[i].Ma-cy[i].Mc;
			if(cy[i].Ma==cy[i].m1) cy[i].mn=1;
			else if(cy[i].Ma==cy[i].m2) cy[i].mn=2;
			else if(cy[i].Ma==cy[i].m3) cy[i].mn=3;
			if(cy[i].mn==1) a[1]++;
			else if(cy[i].mn==2) a[2]++;
			else if(cy[i].mn==3) a[3]++;
			Maa+=cy[i].Ma;
			Mxx+=cy[i].Mx;
			Mcc+=cy[i].Mc;
		}
		if(a[1]>mnn)
		{
			ans=Maa;//最大答案值 
			for(int i=1;i<=n;i++)
			{
				mi=114514;
				if(cy[i].mn==1)//取最大值值域内的最小值 
					if(cy[i].m1<mi) mi=cy[i].m1;
			}
			for(int i=1;i<=n;i++)
			{
				mj=-114514;
				if(cy[i].mn==1)//取非最大值值域内的最大值 
				{
					if(cy[i].m3>mj)
						mj=cy[i].m3;	
					if(cy[i].m2>mj)
						mj=cy[i].m2;
				}
			}
			if(cy[v].m2>cy[v].m1)
			vb[1]=cy[v].m2-cy[v].m1;
			else vb[1]=cy[v].m1-cy[v].m2;
			if(cy[v].m3>cy[v].m2)
			vb[2]=cy[v].m3-cy[v].m2;
			else vb[2]=cy[v].m2-cy[v].m3;
			ans-=min(vb[1],vb[2]);
		}
		else if(a[2]>mnn)
		{
			ans=Maa;
			for(int i=1;i<=n;i++)
			{
				mi=114514;
				if(cy[i].mn==2)
					if(cy[i].m2<mi) mi=cy[i].m2;
			}
			for(int i=1;i<=n;i++)
			{
				mj=-114514;
				if(cy[i].mn==2)  
				{
					if(cy[i].m1>mj)
						mj=cy[i].m1;	
					if(cy[i].m3>mj)
						mj=cy[i].m3;
				}
			}
			if(cy[v].m2>cy[v].m1)
			vb[1]=cy[v].m2-cy[v].m1;
			else vb[1]=cy[v].m1-cy[v].m2;
			if(cy[v].m3>cy[v].m2)
			vb[2]=cy[v].m3-cy[v].m2;
			else vb[2]=cy[v].m2-cy[v].m3;
			ans-=min(vb[1],vb[2]);
		}
		else if(a[3]>mnn)
		{
			ans=Maa;
			for(int i=1;i<=n;i++)
			{
				mi=114514;
				if(cy[i].mn==3)
					if(cy[i].m3<mi) mi=cy[i].m3;
			}
			for(int i=1;i<=n;i++)
			{
				mj=-114514;
				if(cy[i].mn==3)  
				{
					if(cy[i].m1>mj)
						mj=cy[i].m1;	
					if(cy[i].m2>mj)
						mj=cy[i].m2;
				}
			}
			if(cy[v].m2>cy[v].m1)
			vb[1]=cy[v].m2-cy[v].m1;
			else vb[1]=cy[v].m1-cy[v].m2;
			if(cy[v].m3>cy[v].m2)
			vb[2]=cy[v].m3-cy[v].m2;
			else vb[2]=cy[v].m2-cy[v].m3;
			ans-=min(vb[1],vb[2]);
		}
		else if(a[1]<=mnn&&a[2]<=mnn&&a[3]<=mnn)
		{
			ans=Maa; 
		}
		if(v==1)
		{
			cout<</*"ans="<<*/ans<<endl;
		}
			beat[v]=ans;
		if(v>1&&v!=2) cout<</*"beat2="<<*/beat[v]-beat[v-1]<<endl;
		a[1]=0,a[2]=0,a[3]=0;
		if(v==2) cout<<beat[v]-beat[v-1]-1<<endl;
		ans=0;
	}
	return 0;
}
