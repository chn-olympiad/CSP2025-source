#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t;
int n;
int a[100010][4];
int qwq[100010];
bool f=0;
int ans=0;

int cb[50020][2];
int cnt[2];

void exchange1(int x)
{
	int min=1;
	for(int i=0;i<cnt[1];i++)
	{	if( a[cb[i][1]][1]<a[cb[min][1]][1] )
		{	min=i;	}
	}
	if( a[cb[min][1]][1]+a[x][2]<a[x][1]+a[cb[min][1]][2] )
	{
		cb[cnt[0]][0]=cb[min][1];cnt[0]+=1;cnt[1]-=1;
		cb[min][1]=x;
	}
	else
	{	cb[cnt[0]][0]=x;cnt[0]+=1;cnt[1]-=1;	}
	return ;
}

void exchange2(int x)
{ 
	int min=1;
	for(int i=0;i<cnt[0];i++)
	{	if( a[cb[i][0]][2]<a[cb[min][0]][2] )
		{	min=i;	}
	}
	if( a[cb[min][0]][2]+a[x][1]<a[x][2]+a[cb[min][0]][1] )			//写过最石山的代码莫过于此了。。 
	{
		cb[cnt[1]][1]=cb[min][0];cnt[1]+=1;cnt[0]-=1; 
		cb[min][0]=x;
	}
	else
	{	cb[cnt[1]][1]=x;cnt[1]+=1;cnt[0]-=1;	}
	return ;
}


int main()
{
	/*
	FJ-S00396
	不许再吃巧克力了！你就是嘴馋！ ......最后一块。......最后吃了很多块。 
	17:30看到窗户外面有火烧云。
	老师突然关掉空调打开了窗户。。风好大。。好冷。。
	17:48天黑了。 
	大概还是我太菜了罢。
	17:53想颓了。。调了这么久T1还是不会。。部分都没打好。 
	不知道为什么答案对了。对。
	结束前二十分钟改文件输入输出的时候突然炸了。。幸好调好了。吓死我了。
	但其实也只有十几分。qwq。
	就这样罢。拜拜。 
	*/
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--)
	{
		f=0;ans=0;
		memset(cb,0,sizeof(cb));
		cnt[0]=0;cnt[1]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{	for(int k=1;k<=3;k++)
			{	scanf("%d",&a[i][k]);
				if( k==2 && a[i][k]!=0 )
				{	f=1;	}
			}
		}
		
		if(n==2)
		{
			int a1=0,b1=0,a2=0,b2=0;
			for(int i=1;i<=3;i++)
			{	if( a[1][i]>=a[1][a1]  )
				{	a2=a1;a1=i;		}
				if( a[1][i]>=a[1][a2] && i!=a1 )
				{	a2=i;	}
				if( a[2][i]>=a[2][b1]  )
				{	b2=b1;b1=i;		}
				if( a[1][i]>=a[1][b2] && i!=b1 )
				{	b2=i;	}
			}
			
			if( a1==b1 )
			{
				if( a[1][a1]+a[2][b2]>a[2][b1]+a[1][a2] )
				{	printf("%d\n",a[1][a1]+a[2][b2]);	}
				else
				{	printf("%d\n",a[1][a2]+a[2][b1]);	}
			}
			else
			{	printf("%d\n",a[1][a1]+a[2][b1]);	}
			continue;
		}
		
		if(f==0)
		{
			for(int i=1;i<=n;i++)
			{	qwq[i]=a[i][1];	}
			sort(qwq+1,qwq+n+1);
			ans=0;
			for(int i=n;i>n/2;i--)
			{	ans+=qwq[i];	}
			printf("%d\n",ans);
			continue;
		}
		 
		for(int i=1;i<=n;i++)
		{
			if( a[i][1]>a[i][2] )
			{	cb[cnt[1]][1]=i;cnt[1]+=1;	}
			else
			{	cb[cnt[0]][0]=i;cnt[0]+=1;	}
			
			if( cnt[1]>n/2 )
			{	exchange1(i);	}
			if( cnt[0]>n/2 )
			{	exchange2(i);	}
		}
		
		ans=0;
		for(int i=0;i<cnt[1];i++)
		{	ans+=a[cb[i][1]][1];	}
		for(int i=0;i<cnt[0];i++)
		{	ans+=a[cb[i][0]][2];	}
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

