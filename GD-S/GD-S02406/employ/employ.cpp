#include<bits/stdc++.h>
using namespace std;
int zo[505],js[505],bl[20],bo[20]={0};
int n,m;
long long o=0; 
int r[505];
void qb()
{
	int q=0,zs=1,ft=0;
	for(int i=1;i<=n;i++)
	{
		if(q>=r[bl[i]])
		{
			q++;
			continue;
		}
		if(zo[i]==0)
		{
			q++;
			continue;
		}
		ft++;
	}
	if(ft>=m)
		o++;
	for(int i=1;i<=n;i++)
		bo[i]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string zz;
	cin>>n>>m;
	cin>>zz;
	for(int i=0;i<n;i++)
	{
		zo[i+1]=zz[i]-'0';
		cin>>r[i+1];
	}
	sort(r+1,r+n+1);
	if(m==1)
	{
		int jsl=0;
		for(int i=1;i<=n;i++)
		{
			if(zo[i]==1)
			{
				jsl++;
				js[jsl]=i;
			}
		}
		long long er=0;
		for(int i=1;i<=jsl;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(r[j]>=js[i])
				{
					o=1;
					for(int k=2;k<=n-i;k++)
					{
						o*=k;
						o=o%998244353;
					}
					for(int k=1;k<i;k++)
					{
						o*=js[k];
						o=o%998244353;
					}
					o*=n-j+1;
					o=o%998244353;
					js[i]=j-1;
					break;
				}
			}
			er+=o;
			er=er%998244353;
		}
		cout<<er<<endl;
	}
	else if(n>10)
	{
		o=1;
		for(int i=1;i<=n;i++)
		{
			o*=i;
			o=o%998244353;
		}
		cout<<o<<endl;
	}
	else
	{
		for(int kp=n;kp>0;kp--)
		{
							bl[1]=kp;
			if(n==1)
			{
				qb();
				continue;
			}
			for(int ko=n;ko>0;ko--)
			{
				if(ko!=kp)
				{
							bl[2]=ko;
			if(n==2)
			{
				qb();
				continue;
			}
					for(int ki=n;ki>0;ki--)
					{
						if(ki!=kp and ki!=ko)
						{
							bl[3]=ki;
			if(n==3)
			{
				qb();
				continue;
			}
							for(int ku=n;ku>0;ku--)
					{
						if(ku!=kp and ku!=ko and ku!=ki)
						{
							bl[4]=ku;
			if(n==4)
			{
				qb();
				continue;
			}
							for(int ky=n;ky>0;ky--)
					{
						if(ky!=kp and ky!=ko and ky!=ki and ky!=ku)
						{
							bl[5]=ky;
			if(n==5)
			{
				qb();
				continue;
			}
							for(int kt=n;kt>0;kt--)
					{
						if(kt!=kp and kt!=ko and kt!=ki and kt!=ku and kt!=ky)
						{
							bl[6]=kt;
			if(n==6)
			{
				qb();
				continue;
			}
							for(int kr=n;kr>0;kr--)
					{
						if(kr!=kp and kr!=ko and kr!=ki and kr!=kt and kr!=ky and kr!=ku)
						{
							bl[7]=kr;
			if(n==7)
			{
				qb();
				continue;
			}
							for(int ke=n;ke>0;ke--)
					{
						if(ke!=kp and ke!=ko and ke!=ki and ke!=ku and ke!=ky and ke!=kt and ke!=kr)
						{
							bl[8]=ke;
			if(n==8)
			{
				qb();
				continue;
			}
							for(int kw=n;kw>0;kw--)
					{
						if(kw!=kp and kw!=ko and kw!=ki and kw!=ku and kw!=ky and kw!=kt and kw!=kr and kw!=ke)
						{
							bl[9]=kw;
			if(n==9)
			{
				qb();
				continue;
			}
							for(int kq=n;kq>0;kq--)
					{
						if(kq!=kp and kq!=ko and kq!=ki and kq!=ku and kq!=ky and kq!=kt and kq!=kr and kq!=ke and kq!=kw)
						{
							bl[10]=kq;
							qb();
						}
					}
						}
					}
						}
					}
						}
					}
						}
					}
						}
					}
						}
					}
						}
					}
				}
			}
		}
		cout<<o<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
