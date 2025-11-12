#include<bits/stdc++.h>
using namespace std;
int a[100003],b[100003],c[100003];
int fp[100003];
struct CHA
{
	int id;
	int ch;
} cha[100003];

int cmd(CHA x,CHA y)
{
	if(x.ch!=y.ch) return x.ch<y.ch;
	else return x.id<y.id;
}

int tj(int n){
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(fp[i]==1) sum=sum+a[i];
		else if(fp[i]==2) sum=sum+b[i];
		else sum=sum+c[i];
	}
	return sum;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >>n;
		int ah=0,bh=0,ch=0;
		for(int i=1;i<=n;i++)
		{
			cin >>a[i] >>b[i] >>c[i];
			int Max=max(max(a[i],b[i]),c[i]);
			if(Max==a[i])
			{
				fp[i]=1;
				ah++;
			}
			else if(Max==b[i])
			{
				fp[i]=2;
				bh++;
			}
			else
			{
				fp[i]=3;
				ch++;
			}
		}
		bool ac=(ah)<=(n/2);
		bool bc=(bh)<=(n/2);
		bool cc=(ch)<=(n/2);
		if(ac && bc && cc)
		{
			cout <<tj(n) <<endl;
			continue;
		}
		else if(!ac)
		{
			int now=1;
			for(int i=1;i<=n;i++)
			{
				if(fp[i]==1)
				{
					cha[now].id=i;
					cha[now].ch=a[i]-max(b[i],c[i]);
					now++;
				}
			}
			now--;
			int ti=now-n/2;
			sort(cha+1,cha+now+1,cmd);
			int zj=tj(n);
			for(int i=1;i<=ti;i++) zj=zj-(a[cha[i].id]-max(b[cha[i].id],c[cha[i].id]));
			cout <<zj <<endl;
		}
		else if(!bc)
		{
			int now=1;
			for(int i=1;i<=n;i++)
			{
				if(fp[i]==2)
				{
					cha[now].id=i;
					cha[now].ch=b[i]-max(a[i],c[i]);
					now++;
				}
			}
			now--;
			int ti=now-n/2;
			sort(cha+1,cha+now+1,cmd);
			int zj=tj(n);
			for(int i=1;i<=ti;i++) zj=zj-(b[cha[i].id]-max(a[cha[i].id],c[cha[i].id]));
			cout <<zj <<endl;
		}
		else
		{
			int now=1;
			for(int i=1;i<=n;i++)
			{
				if(fp[i]==3)
				{
					cha[now].id=i;
					cha[now].ch=c[i]-max(a[i],b[i]);
					now++;
				}
			}
			now--;
			int ti=now-n/2;
			sort(cha+1,cha+now+1,cmd);
			int zj=tj(n);
			for(int i=1;i<=ti;i++) zj=zj-(c[cha[i].id]-max(a[cha[i].id],b[cha[i].id]));
			cout <<zj <<endl;
		}
	}
	return 0;
}
