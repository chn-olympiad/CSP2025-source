#include<bits/stdc++.h>
using namespace std;
struct chengyuan {
	long long a1,a2,a3;
} a[100005];
struct bijiao {
	long long m1,t1;
}ma[100005],mb[100005];
bool cmp(bijiao xxx,bijiao yyy) {
	return xxx.m1<yyy.m1;
}
bool ccc(chengyuan xx,chengyuan yy)
{
	return xx.a1>yy.a1;
}
long long suma[100005],sumb[100005],sumc[100005],s1,s2,s3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		long long n;
		long long ans=0;
		scanf("%lld",&n);
		bool f1=0;
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a2!=0 || a[i].a3!=0) f1=1;
			long long maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(maxn==a[i].a1) {
				suma[++s1]=i;
				ans+=a[i].a1;
			}
			if(maxn==a[i].a2) {
				sumb[++s2]=i;
				ans+=a[i].a2;
			}
			if(maxn==a[i].a3) {
				sumc[++s3]=i;
				ans+=a[i].a3;
			}
		}
		if(f1==0)
		{
			sort(a+1,a+n+1,ccc);
			ans=0;
			for(int i=1; i<=n/2; i++)
			{
				ans+=a[i].a1;
			}
			printf("%lld\n",ans);
			s1=0;
			s2=0;
			s3=0;
			continue;
		}
		if(s1<=n/2 && s2<=n/2 && s3<=n/2) {
			printf("%lld\n",ans);
			s1=0;
			s2=0;
			s3=0;
			continue;
		}
		if(s1>n/2) {
			if(s2<n/2 && s3>=n/2) {
				while(s1>n/2) {
					long long minn=a[suma[1]].a1-a[suma[1]].a2,tt=1;
					for(int i=2; i<=s1; i++) {
						if(minn>abs(a[suma[i]].a1-a[suma[i]].a2)) {
							minn=a[suma[i]].a1-a[suma[i]].a2;
							tt=i;
						}
					}
					for(int i=tt; i<=s1; i++) {
						suma[i]=suma[i+1];
					}
					s1--;
					s2++;
					ans-=minn;
				}
			} else if(s2>=n/2 && s3<n/2) {
				while(s1>n/2) {
					long long minn=a[suma[1]].a1-a[suma[1]].a3,tt=1;
					for(int i=2; i<=s1; i++) {
						if(minn>a[suma[i]].a1-a[suma[i]].a3) {
							minn=a[suma[i]].a1-a[suma[i]].a3;
							tt=i;
						}
					}
					for(int i=tt; i<=s1; i++) {
						suma[i]=suma[i+1];
					}
					s1--;
					s3++;
					ans-=minn;
				}
			} else {
				for(int i=1; i<=s1; i++) {
					ma[i].m1 =a[suma[i]].a1-a[suma[i]].a2;
					ma[i].t1=i;
					mb[i].m1=a[suma[i]].a1-a[suma[i]].a3;
					mb[i].t1=i;
				}
				sort(ma+1,ma+s1+1,cmp);
				sort(mb+1,mb+s1+1,cmp);
				int tt1=1,tt2=1;
				while(s1>n/2 && s2<n/2 && s3<n/2) {
					if(ma[tt1].m1 <mb[tt2].m1 ) {
						ans-=ma[tt1].m1 ;
						for(int i=ma[tt1].t1; i<=s1; i++) {
							suma[i]=suma[i+1];
						}
						bool ffff=0;
						for(int i=1; i<=s1; i++) {
							if(mb[i].t1>=ma[tt1].t1) {
								ffff=1;
							}
							if(ffff==1) {
								mb[i]=mb[i+1];
							}
						}
						tt1++;
						s1--;
						s2++;
					} else {
						ans-=mb[tt2].m1 ;
						for(int i=mb[tt2].t1; i<=s1; i++) {
							suma[i]=suma[i+1];
						}
						bool ffff=0;
						for(int i=1; i<=s1; i++) {
							if(ma[i].t1==mb[tt2].t1) {
								ffff=1;
							}
							if(ffff==1) {
								ma[i]=ma[i+1];
							}
						}
						tt2++;
						s1--;
						s3++;
					}
				}
				if(s1>n/2 && s2>=n/2) {
					while(s1>n/2) {
						long long minn=a[suma[1]].a1-a[suma[1]].a3,tt=1;
						for(int i=2; i<=s1; i++) {
							if(minn>a[suma[i]].a1-a[suma[i]].a3) {
								minn=a[suma[i]].a1-a[suma[i]].a3;
								tt=i;
							}
						}
						for(int i=tt; i<=s1; i++) {
							suma[i]=suma[i+1];
						}
						s1--;
						s3++;
						ans-=minn;
					}
				} else if(s1>n/2 && s3>=n/2) {
					while(s1>n/2) {
						long long minn=a[suma[1]].a1-a[suma[1]].a2,tt=1;
						for(int i=2; i<=s1; i++) {
							if(minn>a[suma[i]].a1-a[suma[i]].a2) {
								minn=a[suma[i]].a1-a[suma[i]].a2;
								tt=i;
							}
						}
						for(int i=tt; i<=s1; i++) {
							suma[i]=suma[i+1];
						}
						s1--;
						s2++;
						ans-=minn;
					}
				}
			}
		}
		if(s2>n/2) {
			if(s1<n/2 && s3>=n/2) {
				while(s2>n/2) {
					long long minn=a[sumb[1]].a2-a[sumb[1]].a1,tt=1;
					for(int i=2; i<=s2; i++) {
						if(minn>a[sumb[i]].a2-a[sumb[i]].a1) {
							minn=a[sumb[i]].a2-a[sumb[i]].a1;
							tt=i;
						}
					}
					for(int i=tt; i<=s2; i++) {
						sumb[i]=sumb[i+1];
					}
					s2--;
					s1++;
					ans-=minn;
				}
			} else if(s1>=n/2 && s3<n/2) {
				while(s2>n/2) {
					long long minn=a[sumb[1]].a2-a[sumb[1]].a3,tt=1;
					for(int i=2; i<=s2; i++) {
						if(minn>a[sumb[i]].a2-a[sumb[i]].a3) {
							minn=a[sumb[i]].a2-a[sumb[i]].a3;
							tt=i;
						}
					}
					for(int i=tt; i<=s2; i++) {
						sumb[i]=sumb[i+1];
					}
					s2--;
					s3++;
					ans-=minn;
				}
			} else {
				for(int i=1; i<=s2; i++) {
					ma[i].m1 =a[sumb[i]].a2-a[sumb[i]].a1;
					ma[i].t1=i;
					mb[i].m1=a[sumb[i]].a2-a[sumb[i]].a3;
					mb[i].t1=i;
				}
				sort(ma+1,ma+s2+1,cmp);
				sort(mb+1,mb+s2+1,cmp);
				int tt1=1,tt2=1;
				while(s2>n/2 && s1<n/2 && s3<n/2) {
					if(ma[tt1].m1 <mb[tt2].m1 ) {
						ans-=ma[tt1].m1 ;
						for(int i=ma[tt1].t1; i<=s2; i++) {
							sumb[i]=sumb[i+1];
						}
						bool ffff=0;
						for(int i=1; i<=s2; i++) {
							if(mb[i].t1==ma[tt1].t1) {
								ffff=1;
							}
							if(ffff==1) {
								mb[i]=mb[i+1];
							}
						}
						tt1++;
						s2--;
						s1++;
					} else {
						ans-=mb[tt2].m1 ;
						for(int i=mb[tt2].t1; i<=s2; i++) {
							sumb[i]=sumb[i+1];
						}
						bool ffff=0;
						for(int i=1; i<=s2; i++) {
							if(ma[i].t1==mb[tt2].t1) {
								ffff=1;
							}
							if(ffff==1) {
								ma[i]=ma[i+1];
							}
						}
						tt2++;
						s2--;
						s3++;
					}
				}
				if(s2>n/2 && s1>=n/2) {
					while(s2>n/2) {
						long long minn=a[sumb[1]].a2-a[sumb[1]].a3,tt=1;
						for(int i=2; i<=s2; i++) {
							if(minn>a[sumb[i]].a2-a[sumb[i]].a3) {
								minn=a[sumb[i]].a2-a[sumb[i]].a3;
								tt=i;
							}
						}
						for(int i=tt; i<=s2; i++) {
							sumb[i]=sumb[i+1];
						}
						s2--;
						s3++;
						ans-=minn;
					}
				} else if(s2>n/2 && s3>=n/2) {
					while(s2>n/2) {
						long long minn=a[sumb[1]].a2-a[sumb[1]].a1,tt=1;
						for(int i=2; i<=s2; i++) {
							if(minn>a[sumb[i]].a2-a[sumb[i]].a1) {
								minn=a[sumb[i]].a2-a[sumb[i]].a1;
								tt=i;
							}
						}
						for(int i=tt; i<=s2; i++) {
							sumb[i]=sumb[i+1];
						}
						s2--;
						s1++;
						ans-=minn;
					}
				}
			}
		}
		if(s3>n/2) {
			if(s1<n/2 && s2>=n/2) {
				while(s3>n/2) {
					long long minn=a[sumc[1]].a3-a[sumb[1]].a1,tt=1;
					for(int i=2; i<=s3; i++) {
						if(minn>a[sumc[i]].a3-a[sumc[i]].a1) {
							minn=a[sumc[i]].a3-a[sumc[i]].a1;
							tt=i;
						}
					}
					for(int i=tt; i<=s3; i++) {
						sumc[i]=sumc[i+1];
					}
					s3--;
					s1++;
					ans-=minn;
				}
			} else if(s1>=n/2 && s2<n/2) {
				while(s3>n/2) {
					long long minn=a[sumc[1]].a3-a[sumc[1]].a2,tt=1;
					for(int i=2; i<=s3; i++) {
						if(minn>a[sumc[i]].a3-a[sumc[i]].a2) {
							minn=a[sumc[i]].a3-a[sumc[i]].a2;
							tt=i;
						}
					}
					for(int i=tt; i<=s3; i++) {
						sumc[i]=sumc[i+1];
					}
					s3--;
					s2++;
					ans-=minn;
				}
			} else {
				for(int i=1; i<=s3; i++) {
					ma[i].m1 =a[sumb[i]].a3-a[sumb[i]].a1;
					ma[i].t1=i;
					mb[i].m1=a[sumb[i]].a3-a[sumb[i]].a2;
					mb[i].t1=i;
				}
				sort(ma+1,ma+s3+1,cmp);
				sort(mb+1,mb+s3+1,cmp);
				int tt1=1,tt2=1;
				while(s3>n/2 && s1<n/2 && s2<n/2) {
					if(ma[tt1].m1 <mb[tt2].m1 ) {
						ans-=ma[tt1].m1 ;
						for(int i=ma[tt1].t1; i<=s3; i++) {
							sumc[i]=sumc[i+1];
						}
						bool ffff=0;
						for(int i=1; i<=s3; i++) {
							if(mb[i].t1==ma[tt1].t1) {
								ffff=1;
							}
							if(ffff==1) {
								mb[i]=mb[i+1];
							}
						}
						tt1++;
						s3--;
						s1++;
					} else {
						ans-=mb[tt2].m1 ;
						for(int i=mb[tt2].t1; i<=s3; i++) {
							sumc[i]=sumc[i+1];
						}
						bool ffff=0;
						for(int i=1; i<=s3; i++) {
							if(ma[i].t1==mb[tt2].t1) {
								ffff=1;
							}
							if(ffff==1) {
								ma[i]=ma[i+1];
							}
						}
						tt2++;
						s3--;
						s2++;
					}
				}
				if(s3>n/2 && s2>=n/2) {
					while(s3>n/2) {
						long long minn=a[sumc[1]].a3-a[sumc[1]].a1,tt=1;
						for(int i=2; i<=s3; i++) {
							if(minn>a[sumc[i]].a3-a[sumc[i]].a1) {
								minn=a[sumc[i]].a3-a[sumc[i]].a1;
								tt=i;
							}
						}
						for(int i=tt; i<=s3; i++) {
							sumc[i]=sumc[i+1];
						}
						s3--;
						s1++;
						ans-=minn;
					}
				} else if(s3>n/2 && s1>=n/2) {
					while(s3>n/2) {
						long long minn=a[sumc[1]].a3-a[sumc[1]].a2,tt=1;
						for(int i=2; i<=s3; i++) {
							if(minn>a[sumc[i]].a3-a[sumc[i]].a2) {
								minn=a[sumc[i]].a3-a[sumc[i]].a2;
								tt=i;
							}
						}
						for(int i=tt; i<=s3; i++) {
							sumc[i]=sumc[i+1];
						}
						s3--;
						s2++;
						ans-=minn;
					}
				}
			}
		}
		printf("%lld\n",ans);
		s1=0;
		s2=0;
		s3=0;
	}
	return 0;
}
