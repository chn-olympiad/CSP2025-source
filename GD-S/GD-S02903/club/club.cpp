#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
//代码有误，没考虑全 
struct node
{
	long long a,b,c;
};

long long T,n,ma,now,ans;
long long t1,t2;//t1 选择部门 t2 满意值 
long long cnt1,cnt2,cnt3;
node peo[100005];//人 

bool cmp(node x,node y)
{
	long long t_x,t_y;
	
	t_x=max(x.a,x.b);t_x=max(t_x,x.c);
	t_y=max(y.a,y.b);t_y=max(t_y,y.c);
	
	return t_x>t_y;
}

void get()
{
	if(cnt1<ma && cnt2<ma && cnt3<ma)
	{
		t1=1;t2=peo[now].a;
		
		if(peo[now].b>t2)
		{
			t1=2;t2=peo[now].b;
		}
		
		if(peo[now].c>t2)
		{
			t1=3;t2=peo[now].c;
		}
	}
	else if(cnt1>=ma)
	{
		if(peo[now].b>peo[now].c)
		{
			t1=2;t2=peo[now].b;
		}
		else
		{
			t1=3;t2=peo[now].c;
		}
	}
	else if(cnt2>=ma)
	{
		if(peo[now].a>peo[now].c)
		{
			t1=1;t2=peo[now].a;
		}
		else
		{
			t1=3;t2=peo[now].c;
		}
	}
	else
	{
		if(peo[now].a>peo[now].b)
		{
			t1=1;t2=peo[now].a;
		}
		else
		{
			t1=2;t2=peo[now].b;
		}
	}
	
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	
	for(;T>=1;T--)
	{
		now=1;ans=0;
		cnt1=0;cnt2=0;cnt3=0;
		
		cin>>n;
		ma=n/2;
		
		for(long long i=1;i<=n;i++)
		{
			cin>>peo[i].a>>peo[i].b>>peo[i].c;
		}
		
		sort(peo+1,peo+1+n,cmp);
		
		for(;now<=n;now++)
		{
			get();
			
			ans+=t2;
			
			if(t1==1)cnt1++;
			else if(t1==2)cnt2++;
			else cnt3++;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
