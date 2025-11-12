#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N][4];
struct alg
{
	int seat;
	int k[4];
}u[N],v[N],w[N];
int u2[N],v2[N],w2[N]; //有多个兴趣的人的位置 
int u21,v21,w21;
int u1,v1,w1;
int tpa[N]; //用于特判 

void put(int i,int t) //放入 
{
	if(t==1)
	{
		u[++u1].seat=i;
		for(int j=1; j<=3; ++j)
			u[u1].k[j]=a[i][j];
	}
	else if(t==2)
	{
		v[++v1].seat=i;
		for(int j=0; j<=3; ++j)
			v[v1].k[j]=a[i][j];
	}
	else
	{
		w[++w1].seat=i;
		for(int j=1; j<=3; ++j)
			w[w1].k[j]=a[i][j];
	}
}
void fl(int i) //分类 
{
	if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
	{
		if(a[i][2]>a[i][3])
			a[i][0]=123;
		else if(a[i][3]>a[i][2])
			a[i][0]=132;
		else
		{
			a[i][0]=14023;
			u2[++u21]=u1+1;
		}
		put(i,1);
	}
	else if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
	{
		if(a[i][3]>a[i][1])
			a[i][0]=231;
		else if(a[i][1]>a[i][3])
			a[i][0]=213;
		else
		{
			a[i][0]=24013;
			v2[++v21]=v1+1;
		}
		put(i,2);
	}
	else if(a[i][3]>a[i][2] && a[i][3]>a[i][1])
	{
		if(a[i][2]>a[i][1])
			a[i][0]=321;
		else if(a[i][1]>a[i][2])
			a[i][0]=312;
		else
		{
			a[i][0]=34012; //40是分隔，表示其后的2位相等 
			w2[++w21]=w1+1;
		}
		put(i,3);
	}
	else if(a[i][1]==a[i][2] && a[i][2]==a[i][3])
	{
		a[i][0]=100; //全能 
		w2[++w21]=w1+1;
		//put(i,1);
		//put(i,2);
		put(i,3);
	}
	else if(a[i][1]==a[i][2])
	{
		a[i][0]=40123;
		u2[++u21]=u1+1;
		put(i,1);
		//put(i,2);
	}
	else if(a[i][2]==a[i][3])
	{
		a[i][0]=40231;
		v2[++v21]=v1+1;
		put(i,2);
		//put(i,3);
	}
	else if(a[i][1]==a[i][3])
	{
		a[i][0]=40132; //表示兴趣的排序 
		w2[++w21]=w1+1;
		//put(i,1);
		put(i,3);
	}
}

bool cmp1(alg x,alg y)
{
	if(a[x.seat][1]>a[y.seat][1])
		return true;
	return false;
}
bool cmp2(alg x,alg y)
{
	if(a[x.seat][2]>a[y.seat][2])
		return true;
	return false;
}
bool cmp3(alg x,alg y)
{
	if(a[x.seat][3]>a[y.seat][3])
		return true;
	return false;
}
bool cmp4(int x,int y)
{
	if(x>y)
		return true;
	return false;
}
int tp() //特判 
{
	for(int i=1; i<=n; ++i)
	{
		if(a[i][3]!=0)
			return 0;
	}
	bool flag=true; //true特殊情况A 
	for(int i=1; i<=n; ++i)
	{
		if(a[i][2]!=0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		int t=0;
		for(int i=1; i<=n; ++i)
			tpa[i]=a[i][1];
		sort(tpa+1, tpa+1+n,cmp4);
		for(int i=1; i<=n/2; ++i)
		{
			t+=tpa[i];
		}
		return t;
	}
	else
	{
		int t=0;
		for(int i=1; i<=n; ++i)
		{
			if(a[i][1]>a[i][2])
			{
				put(i,1);
			}
			else if(a[i][2]>a[i][1])
			{
				put(i,2);
			}
			else
			{
				put(i,3);
			}
		}
		if(u1>(n/2))
		{
			sort(u+1,u+1+u1,cmp1);
			while(u1>(n/2))
			{
				++v1;
				v[v1]=u[u1];
				--u1;
			}
			for(int i=1; i<=w1; ++i)
				v[++v1]=w[i];
		}
		else if(v1>(n/2))
		{
			sort(v+1,v+1+v1,cmp2);
			while(v1>(n/2))
			{
				++u1;
				u[u1]=v[v1];
				--v1;
			}
			for(int i=1; i<=w1; ++i)
				v[++v1]=w[i];
		}
		else if(w1>0)
		{
			for(int i=1; i<=w1; ++i)
				t+=w[i].k[1];
		}
		for(int i=1; i<=u1; ++i)
			t+=u[i].k[1];
		for(int i=1; i<=v1; ++i)
			t+=v[i].k[2];
		return t;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for(int z=1; z<=t; ++z)
	{
		int ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=3; ++j)
				scanf("%d",&a[i][j]);
			fl(i);
		}
		ans=tp();
		if(ans!=0)
		{
			printf("%d\n",ans);
			u1=0;
			v1=0;
			w1=0;
			u21=0;
			v21=0;
			w21=0;
			continue;
		}
		if(u1>(n/2))
			{
				for(int j=1; j<=u21 && u1>(n/2); ++j)
				{
					swap(u[u2[j]],u[u1]);
					int t1=u[u1].k[0];
					if(t1==14023 || t1==40123)
					{
						++v1;
						v[v1]=u[u1];
						++v21;
						v2[v21]=v1;
					}
					--u1;
				}
				if(u1>(n/2))
				{
					sort(u+1,u+1+u1,cmp1);
					while(u1>(n/2))
					{
						if(u[u1].k[0]==123)
						{
							++v1;
							v[v1]=u[u1];
						}
						else
						{
							++w1;
							w[w1]=u[u1];
						}
						--u1;
					}
				}
			}
			if(v1>(n/2))
			{
				for(int j=1; j<=v21 && v1>(n/2); ++j)
				{
					swap(v[v2[j]],u[u1]);
					int t1=v[v1].k[0];
					if(t1==24013)
					{
						++u1;
						u[u1]=v[v1];
						++u21;
						u2[u21]=v1;
					}
					if(t1==40231)
					{
						++w1;
						w[w1]=v[v1];
						++w21;
						w2[w21]=v1;
					}
					--v1;
				}
				if(v1>(n/2))
				{
					sort(v+1,v+1+v1,cmp2);
					while(v1>(n/2))
					{
						if(v[v1].k[0]==213)
						{
							++u1;
							u[u1]=v[v1];
						}
						else
						{
							++w1;
							w[w1]=v[v1];
						}
						--v1;
					}
				}
			}
			if(w1>(n/2))
			{
				for(int j=1; j<=w21 && w1>(n/2); ++j)
				{
					swap(w[w2[j]],w[w1]);
					int t1=w[w1].k[0];
					if(t1==34012 || t1==40132 || t1==100)
					{
						++u1;
						u[u1]=w[w1];
						++u21;
						u2[u21]=u1;
					}
					--w1;
				}
				if(w1>(n/2))
				{
					sort(w+1,w+1+w1,cmp3);
					while(w1>(n/2))
					{
						if(w[w1].k[0]==321)
						{
							++v1;
							v[v1]=w[w1];
						}
						else
						{
							++u1;
							u[u1]=w[w1];
						}
						--w1;
					}
				}
			}
		for(int i=1; i<=u1; ++i)
		{
			ans+=u[i].k[1];
		}
		for(int i=1; i<=v1; ++i)
		{
			ans+=v[i].k[2];
		}
		for(int i=1; i<=w1; ++i)
		{
			ans+=w[i].k[3];
		}
		printf("%d\n",ans);
		u1=0;
		v1=0;
		w1=0;
		u21=0;
		v21=0;
		w21=0;
	}
	return 0;
}
