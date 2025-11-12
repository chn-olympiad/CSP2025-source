#include<bits/stdc++.h>
using namespace std;

const long long d=998244353;
long long n,m,c[501],l,s=1,f[501],q;
bool w[501];
char x[501];

void ms(int r1,int r2,int r3)
{
	if(c[r1]<f[r2]+q)
	{
		q++;
	}
	if(c[r1]>f[r2] and x[r2-1]=='1')
	{
		r3++;
	}
	//cout<<r1<<" "<<r2<<" "<<r3<<endl;
	if(r3>=m)
	{
		s++;
		return;
	}
	if(r2==n)
	{
		if(c[r1]<f[r2]+q-1)
		{
			q--;
		}
		return; 
	}
	for(int i=1;i<=n;i++)
	{
		if(!w[i])
		{
			w[i]=1;
			ms(i,r2+1,r3);
			w[i]=0;
		}
	}
	if(c[r1]<f[r2]+q-1)
	{
		q--;
	}
}

int main()
{
	freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",x);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+(x[i-1]=='0');
	}
	sort(c+1,c+n+1);
	c[0]=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(x[i]=='1')
		{
			l++;
		}
	}
	if(l==n)
	{
		for(int i=1;i<=n;i++)
		{
			s=(s*i)%d;
		}
		printf("%d",s);
		return 0;
	}
	if(m==n)
	{
		if(l==n)
		{
			for(int i=1;i<=n;i++)
			{
				s=(s*i)%d;
			}
			printf("%d",s);
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			s=(s*i)%d;
		}
		long long k=1;
		bool v1=0,v2=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[j]>=c[i])
				{
					v2=0;
					k=k*(n-j-i+2);
					if(k<=0)
					{
						v1=1;
						break;
					}
					k=k%d;
				}
			}
		}
		if(!v2 and !v1)
		{
			printf("%d",(s+d-k)%d);
		}
		else
		{
			printf("%d",s);
		}
		return 0;
	}
	ms(0,0,0);
	printf("%d",s-1);
	return 0;
}


