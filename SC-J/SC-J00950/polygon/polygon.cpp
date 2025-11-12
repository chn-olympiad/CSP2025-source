#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int n;
int zuhe(int a,int b)
{
	int c=1,d=2*b-a;
	if(d<0)
	{
		for(int i=a;i>=a-b+1;--i)
		{
			c*=i;
		}
		for(int i=b;i>=1;--i)
		{
			c/=i;
		}	
	}
	else 
	{
		for(int i=a;i>=a-b+1+d;--i)
		{
			c*=i;
		}
		for(int i=b-d;i>=1;--i)
		{
			c/=i;
		}
	}
	return c;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=INT_MIN;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	int ans=0;
	if(maxx==1)
	{
		for(int i=3;i<=n;++i)
		{
			ans=(ans+zuhe(n,i))%998244353;
		}
	}
	else
	{
		sort(a+1,a+1+n);
		if(n>=3)
			for(int i=1;i<=n-2;++i)
				for(int j=i+1;j<=n-1;++j)
					for(int k=i+1;k<=n;++k)
						if(a[i]+a[j]>a[k]) ans++;
		if(n>=4)
			for(int i=1;i<=n-3;++i)
				for(int j=i+1;j<=n-2;++j)
					for(int k=j+1;k<=n-1;++k)
						for(int l=k+1;l<=n;++l)
						    if(a[i]+a[j]+a[k]>a[l]) ans++;
		if(n>=5)
			for(int i=1;i<=n-4;++i)
				for(int j=i+1;j<=n-3;++j)
					for(int k=j+1;k<=n-2;++k)
						for(int l=k+1;l<=n-1;++l)
							for(int m=l+1;m<=n;++m)
						    	if(a[i]+a[j]+a[k]+a[l]>a[m]) ans++;
		if(n>=6)
			for(int i=1;i<=n-5;++i)
				for(int j=i+1;j<=n-4;++j)
					for(int k=j+1;k<=n-3;++k)
						for(int l=k+1;l<=n-2;++l)
							for(int m=l+1;m<=n-1;++m)
								for(int c=m+1;c<=n;++c)
						   			if(a[i]+a[j]+a[k]+a[l]+a[m]>a[c]) ans++;
		if(n>=7)
			for(int i=1;i<=n-6;++i)
				for(int j=i+1;j<=n-5;++j)
					for(int k=j+1;k<=n-4;++k)
						for(int l=k+1;l<=n-3;++l)
							for(int m=l+1;m<=n-2;++m)
								for(int c=m+1;c<=n-1;++c)
									for(int d=c+1;d<=n;++d)
						   				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]>a[d]) ans++;
		if(n>=8)
			for(int i=1;i<=n-7;++i)
				for(int j=i+1;j<=n-6;++j)
					for(int k=j+1;k<=n-5;++k)
						for(int l=k+1;l<=n-4;++l)
							for(int m=l+1;m<=n-3;++m)
								for(int c=m+1;c<=n-2;++c)
									for(int d=c+1;d<=n-1;++d)
										for(int e=d+1;e<=n;++e)
						   					if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]>a[e]) ans++;
		if(n>=9)
			for(int i=1;i<=n-8;++i)
				for(int j=i+1;j<=n-7;++j)
					for(int k=j+1;k<=n-6;++k)
						for(int l=k+1;l<=n-5;++l)
							for(int m=l+1;m<=n-4;++m)
								for(int c=m+1;c<=n-3;++c)
									for(int d=c+1;d<=n-2;++d)
										for(int e=d+1;e<=n-1;++e)
											for(int f=e+1;f<=n;++f)
						   						if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]>a[f]) ans++;
		if(n>=10)
			for(int i=1;i<=n-9;++i)
				for(int j=i+1;j<=n-8;++j)
					for(int k=j+1;k<=n-7;++k)
						for(int l=k+1;l<=n-6;++l)
							for(int m=l+1;m<=n-5;++m)
								for(int c=m+1;c<=n-4;++c)
									for(int d=c+1;d<=n-3;++d)
										for(int e=d+1;e<=n-2;++e)
											for(int f=e+1;f<=n-1;++f)
												for(int g=f+1;g<=n;++g)
						   							if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]>a[g]) ans++;
		if(n>=11)
			for(int i=1;i<=n-10;++i)
				for(int j=i+1;j<=n-9;++j)
					for(int k=j+1;k<=n-8;++k)
						for(int l=k+1;l<=n-7;++l)
							for(int m=l+1;m<=n-6;++m)
								for(int c=m+1;c<=n-5;++c)
									for(int d=c+1;d<=n-4;++d)
										for(int e=d+1;e<=n-3;++e)
											for(int f=e+1;f<=n-2;++f)
												for(int g=f+1;g<=n-1;++g)
													for(int h=g+1;h<=n;++h) 
						   								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]>a[h]) ans++;
		if(n>=12)
			for(int i=1;i<=n-11;++i)
				for(int j=i+1;j<=n-10;++j)
					for(int k=j+1;k<=n-9;++k)
						for(int l=k+1;l<=n-8;++l)
							for(int m=l+1;m<=n-7;++m)
								for(int c=m+1;c<=n-6;++c)
									for(int d=c+1;d<=n-5;++d)
										for(int e=d+1;e<=n-4;++e)
											for(int f=e+1;f<=n-3;++f)
												for(int g=f+1;g<=n-2;++g)
													for(int h=g+1;h<=n-1;++h) 
														for(int o=h+1;o<=n;++o)
						   									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>a[o]) ans++;					   								
		if(n>=13)
			for(int i=1;i<=n-12;++i)
				for(int j=i+1;j<=n-11;++j)
					for(int k=j+1;k<=n-10;++k)
						for(int l=k+1;l<=n-9;++l)
							for(int m=l+1;m<=n-8;++m)
								for(int c=m+1;c<=n-7;++c)
									for(int d=c+1;d<=n-6;++d)
										for(int e=d+1;e<=n-5;++e)
											for(int f=e+1;f<=n-4;++f)
												for(int g=f+1;g<=n-3;++g)
													for(int h=g+1;h<=n-2;++h) 
														for(int o=h+1;o<=n-1;++o)
															for(int p=o+1;p<=n;++p)
																if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]>a[p]) ans++;		
		if(n>=14)
			for(int i=1;i<=n-13;++i)
				for(int j=i+1;j<=n-12;++j)
					for(int k=j+1;k<=n-11;++k)
						for(int l=k+1;l<=n-10;++l)
							for(int m=l+1;m<=n-9;++m)
								for(int c=m+1;c<=n-8;++c)
									for(int d=c+1;d<=n-7;++d)
										for(int e=d+1;e<=n-6;++e)
											for(int f=e+1;f<=n-5;++f)
												for(int g=f+1;g<=n-4;++g)
													for(int h=g+1;h<=n-3;++h) 
														for(int o=h+1;o<=n-2;++o)
															for(int p=o+1;p<=n-1;++p)
																for(int q=p+1;q<=n;++q)
																	if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]>a[q]) ans++;	
		if(n>=15)
			for(int i=1;i<=n-14;++i)
				for(int j=i+1;j<=n-13;++j)
					for(int k=j+1;k<=n-12;++k)
						for(int l=k+1;l<=n-11;++l)
							for(int m=l+1;m<=n-10;++m)
								for(int c=m+1;c<=n-9;++c)
									for(int d=c+1;d<=n-8;++d)
										for(int e=d+1;e<=n-7;++e)
											for(int f=e+1;f<=n-6;++f)
												for(int g=f+1;g<=n-5;++g)
													for(int h=g+1;h<=n-4;++h) 
														for(int o=h+1;o<=n-3;++o)
															for(int p=o+1;p<=n-2;++p)
																for(int q=p+1;q<=n-1;++q)
																	for(int r=q+1;r<=n;++r)
																		if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]+a[q]>a[r]) ans++;		
		if(n>=16)
			for(int i=1;i<=n-15;++i)
				for(int j=i+1;j<=n-14;++j)
					for(int k=j+1;k<=n-13;++k)
						for(int l=k+1;l<=n-12;++l)
							for(int m=l+1;m<=n-11;++m)
								for(int c=m+1;c<=n-10;++c)
									for(int d=c+1;d<=n-9;++d)
										for(int e=d+1;e<=n-8;++e)
											for(int f=e+1;f<=n-7;++f)
												for(int g=f+1;g<=n-6;++g)
													for(int h=g+1;h<=n-5;++h) 
														for(int o=h+1;o<=n-4;++o)
															for(int p=o+1;p<=n-3;++p)
																for(int q=p+1;q<=n-2;++q)
																	for(int r=q+1;r<=n-1;++r)
																		for(int s=r+1;s<=n;++s)
																			if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]+a[q]+a[r]>a[s]) ans++;		
		if(n>=17)
			for(int i=1;i<=n-16;++i)
				for(int j=i+1;j<=n-15;++j)
					for(int k=j+1;k<=n-14;++k)
						for(int l=k+1;l<=n-13;++l)
							for(int m=l+1;m<=n-12;++m)
								for(int c=m+1;c<=n-11;++c)
									for(int d=c+1;d<=n-10;++d)
										for(int e=d+1;e<=n-9;++e)
											for(int f=e+1;f<=n-8;++f)
												for(int g=f+1;g<=n-7;++g)
													for(int h=g+1;h<=n-6;++h) 
														for(int o=h+1;o<=n-5;++o)
															for(int p=o+1;p<=n-4;++p)
																for(int q=p+1;q<=n-3;++q)
																	for(int r=q+1;r<=n-2;++r)
																		for(int s=r+1;s<=n-1;++s)
																			for(int t=s+1;t<=n;++t)
																				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]+a[q]+a[r]+a[s]>a[t]) ans++;		
		if(n>=18)
			for(int i=1;i<=n-17;++i)
				for(int j=i+1;j<=n-16;++j)
					for(int k=j+1;k<=n-15;++k)
						for(int l=k+1;l<=n-14;++l)
							for(int m=l+1;m<=n-13;++m)
								for(int c=m+1;c<=n-12;++c)
									for(int d=c+1;d<=n-11;++d)
										for(int e=d+1;e<=n-10;++e)
											for(int f=e+1;f<=n-9;++f)
												for(int g=f+1;g<=n-8;++g)
													for(int h=g+1;h<=n-7;++h) 
														for(int o=h+1;o<=n-6;++o)
															for(int p=o+1;p<=n-5;++p)
																for(int q=p+1;q<=n-4;++q)
																	for(int r=q+1;r<=n-3;++r)
																		for(int s=r+1;s<=n-3;++s)
																			for(int t=s+1;t<=n-1;++t)
																				for(int u=t+1;u<=n;++u)
																					if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]>a[u]) ans++;		
		if(n>=19)
			for(int i=1;i<=n-18;++i)
				for(int j=i+1;j<=n-17;++j)
					for(int k=j+1;k<=n-16;++k)
						for(int l=k+1;l<=n-15;++l)
							for(int m=l+1;m<=n-14;++m)
								for(int c=m+1;c<=n-13;++c)
									for(int d=c+1;d<=n-12;++d)
										for(int e=d+1;e<=n-11;++e)
											for(int f=e+1;f<=n-10;++f)
												for(int g=f+1;g<=n-9;++g)
													for(int h=g+1;h<=n-8;++h) 
														for(int o=h+1;o<=n-7;++o)
															for(int p=o+1;p<=n-6;++p)
																for(int q=p+1;q<=n-5;++q)
																	for(int r=q+1;r<=n-4;++r)
																		for(int s=r+1;s<=n-3;++s)
																			for(int t=s+1;t<=n-2;++t)
																				for(int u=t+1;u<=n-1;++u)
																					for(int v=u+1;v<=n;++v)
																						if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]>a[v]) ans++;		
		if(n>=20)
			for(int i=1;i<=n-19;++i)
				for(int j=i+1;j<=n-18;++j)
					for(int k=j+1;k<=n-17;++k)
						for(int l=k+1;l<=n-16;++l)
							for(int m=l+1;m<=n-15;++m)
								for(int c=m+1;c<=n-14;++c)
									for(int d=c+1;d<=n-13;++d)
										for(int e=d+1;e<=n-12;++e)
											for(int f=e+1;f<=n-11;++f)
												for(int g=f+1;g<=n-10;++g)
													for(int h=g+1;h<=n-9;++h) 
														for(int o=h+1;o<=n-8;++o)
															for(int p=o+1;p<=n-7;++p)
																for(int q=p+1;q<=n-6;++q)
																	for(int r=q+1;r<=n-5;++r)
																		for(int s=r+1;s<=n-4;++s)
																			for(int t=s+1;t<=n-3;++t)
																				for(int u=t+1;u<=n-2;++u)
																					for(int v=u+1;v<=n-1;++v)
																						for(int w=v+1;w<=n;++w)
																							if(a[i]+a[j]+a[k]+a[l]+a[m]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]>a[w]) ans++;		
	}
	cout<<ans;
	return 0;
}
//CCF让你给骗分点没让你这么给\FUCK CCF 