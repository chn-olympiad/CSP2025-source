#include<bits/stdc++.h>
using namespace std;

const int N = 3e6+5;
long long t,n,a[N],b[N],c[N];
long long d,e,f;//GeShu
long long s;//ZongManYiDu
long long p;//JiaoXiao
long long m;//JiaoDa
long long q,w,r;//ZuiXiaoChaZhi
long long yu;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n;
		d = 0;
		e = 0;
		f = 0;
		s = 0;
		for(int j=1;j<=n;j++)
		{
			yu = 1;
			cin >> a[j] >> b[j] >> c[j];
			if(a[j] >= b[j] && a[j] >= c[j])
			{
				q=min(a[j]-b[j],a[j]-c[j]);
				d++;
				s+=a[j];
			}
			else if(b[j] >= a[j] && b[j] >= c[j])
			{
				w=min(b[j]-a[j],b[j]-c[j]);
				e++;
				s+=b[j];
			}
			else if(c[j] >= a[j] && c[j] >= b[j])
			{
				r=min(c[j]-a[j],c[j]-b[j]);
				f++;
				s+=c[j];
			}
			if(d > n/2)
			{
				d--;
				for(int k=1;k<=d;k++)
				{
					if(min(a[k]-b[k],a[k]-c[k]) < q)
					{
						p=min(a[k],a[j]);
						m=max(a[k],a[j]);
					}
					else
					{
						yu = 0;
					}
				}
				if(yu != 0)
				{
					s-=p;
					if(p == a[j])
					{
						continue;
					}
					else
					{
						s+=m;
					}
				}
				if(b[j] >= c[j])
				{
					e++;
					s+=b[j];
				}
				else
				{
					f++;
					s+=c[j];
				}
			}
			if(e > n/2)
			{
				e--;
				for(int k=1;k<=e;k++)
				{
					if(min(b[k]-a[k],b[k]-c[k]) < w)
					{
						p=min(b[k],b[j]);
						m=max(b[k],b[j]);
					}
					else
					{
						yu = 0;
					}
				}
				if(yu != 0)
				{
					s-=p;
					if(p == b[j])
					{
						continue;
					}
					else
					{
						s+=m;
					}
				}
				if(c[j] >= a[j])
				{
					f++;
					s+=c[j];
				}
				else
				{
					d++;
					s+=a[j];
				}
			}
			if(f > n/2)
			{
				f--; 
				for(int k=1;k<=f;k++)
				{
					if(min(c[k]-a[k],c[k]-b[k]) < r)
					{
						p=min(c[k],c[j]);
						m=max(c[k],c[j]);
					}
					else
					{
						yu = 0;
					}
				}
				if(yu != 0)
				{
					s-=p;
					if(p == c[j])
					{
						continue;
					}
					else
					{
						s+=m;
					}
				}
				if(a[j] >= b[j])
				{
					d++;
					s+=a[j];
				}
				else
				{
					e++;
					s+=b[j];
				}
			}
		}
		cout << s <<endl;
	}
	return 0;
}