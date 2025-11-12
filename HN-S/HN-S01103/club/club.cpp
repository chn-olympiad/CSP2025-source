#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;

struct zz{
	ll a;
	ll b;
	ll c;
};

struct zz2{
	ll a;
	ll b;
};

zz now,nin[N];

int all[4];

int cnt;

bool cmp(zz2 a,zz2 b)
{
	if(a.a>=b.a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool cmp1(zz a,zz b)
{
	if(a.a>=b.a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool cmp2(zz a,zz b)
{
	if(a.b>=b.b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool cmp3(zz a,zz b)
{
	if(a.c>=b.c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int fi[N],se[N],th[N];

int sysrun(int a,int b,int c,int n)
{
	//cout<<a<<" "<<b<<" "<<c<<endl;
	zz2 px[4];
	px[1].a=a;
	px[1].b=1;
	px[2].a=b;
	px[2].b=2;
	px[3].a=c;
	px[3].b=3;
	//cout<<px[1].a<<" "<<px[2].a<<" "<<px[3].a<<endl;
	sort(px+1,px+3+1,cmp);
	//cout<<px[1].a<<" "<<px[2].a<<" "<<px[3].a<<endl;
	//cout<<px[1].b<<" "<<px[2].b<<" "<<px[3].b<<endl;
	if(all[px[1].b]+1<=n/2)
	{
		cnt+=px[1].a;
		all[px[1].b]++;
		//cout<<" "<<px[1].b<<"H "<<px[1].a<<endl;
	}
	else if(all[px[2].b]+1<=n/2)
	{
		cnt+=px[2].a;
		all[px[2].b]++;
		//cout<<" "<<px[2].b<<"H "<<px[2].a<<endl;
	}
	else if(all[px[3].b]+1<=n/2)
	{
		cnt+=px[3].a;
		all[px[3].b]++;
		//cout<<" "<<px[3].b<<"H "<<px[3].a<<endl;
	}
	
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		all[1]=0;
		all[2]=0; 
		all[3]=0;
		
		
		
		for(int i=1;i<=n;i++)
		{
			cin>>nin[i].a>>nin[i].b>>nin[i].c;
			
			//sysrun(now.a,now.b,now.c,n);
		}
		int max=0;
		for(int j=1;j<=3;j++)
		{
			cnt=0;
			all[1]=0;
			all[2]=0;
			all[3]=0;
			if(j==1)
			{
				sort(nin+1,nin+n+1,cmp1);
			}
			if(j==2)
			{
				sort(nin+1,nin+n+1,cmp2);
			}
			if(j==3)
			{
				sort(nin+1,nin+n+1,cmp3);
			}
			for(int i=1;i<=n;i++)
			{
				sysrun(nin[i].a,nin[i].b,nin[i].c,n);
			}
			//cout<<cnt<<" ";
			if(cnt>max)
			{
				max=cnt;
			}
		}
		cout<<max;

	}
	return 0;
}
