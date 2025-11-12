#include<iostream>
#include<cstring> 
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int Max=1e5+10;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-'0',c=getchar();}
	return sum*f;
}
int a[Max][5],jr[5],b[Max],cnt;
int qmax(int x1,int x2,int x3)
{
	int pd=1,maxx=x1;
	if(x2>maxx) maxx=x2,pd=2;
	if(x3>maxx) maxx=x3,pd=3;
	jr[pd]++;
	return maxx; 
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--)
	{
		cnt=0;
		int n;
		long long ans=0;
		n=read();
		for(int i=1;i<=3;i++) jr[i]=0;
		for(int i=1;i<=n;i++) a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		for(int i=1;i<=n;i++) ans+=qmax(a[i][1],a[i][2],a[i][3]);
		if(jr[1]<=n/2&&jr[2]<=n/2&&jr[3]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		else
		{
			int now=0;
			if(jr[1]>n/2) now=1;
			if(jr[2]>n/2) now=2;
			if(jr[3]>n/2) now=3;
			for(int i=1;i<=n;i++)
			{
				int maxx=0;
				for(int j=1;j<=3;j++)
				{
					if(j==now) continue;
					maxx=max(a[i][j],maxx);
				} 
				if(a[i][now]>=maxx) b[++cnt]=a[i][now]-maxx;
			} 
			sort(b+1,b+1+cnt);
			for(int i=1;i<=jr[now]-n/2;i++) ans-=b[i];
			cout<<ans<<endl; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
