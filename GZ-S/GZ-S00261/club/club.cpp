//GZ-S00261 遵义市第四中学 杨嵩涵
#include <bits/stdc++.h>
using namespace std;
const int N=20005;
int t,n;
struct st {
	int a,b,c;
} s[100005],sum;
struct mm {
	int w,num;
} mina,minb,minc;
long long ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {ans=0;sum.a=0;sum.b=0;sum.c=0;
		mina.w=N,minb.w=N,minc.w=N;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i) {
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c) {
				if(sum.a<n/2) {
					sum.a++;
					mina.w=min(mina.w,s[i].a);
					if(mina.w==s[i].a)mina.num=i;
					ans+=s[i].a;
				} else {
					if(s[i].b>=s[i].c) {
						if(s[mina.num].b>=s[mina.num].c) {
							if(s[i].b>s[i].a-mina.w+s[mina.num].b) {
								sum.b++;
								minb.w=min(minb.w,s[i].b);
								if(minb.w==s[i].b)minb.num=i;
								ans+=s[i].b;
							} else { 
								sum.b++;
								ans+=s[i].a-mina.w+s[mina.num].b;
								minb.w=min(minb.w,s[mina.num].b);
								if(minb.w==s[mina.num].b)minb.num=mina.num;
								mina.w=s[i].a;
								mina.num=i;
								for(int j=1; j<=i; ++j) {
									if(mina.w>s[j].a) {
										mina.w=s[j].a;
										mina.num=j;
									}
								}
								
							}
						} else {
							if(s[i].b>s[i].a-mina.w+s[mina.num].c) {
								sum.b++;
								minb.w=min(minb.w,s[i].b);
								if(minb.w==s[i].b)minb.num=i;
								ans+=s[i].b;
							} else {
								sum.c++;
								minc.w=min(minc.w,s[mina.num].c);
								if(minc.w==s[mina.num].c)minc.num=mina.num;
								mina.w=s[i].a;
								mina.num=i;
								for(int j=1; j<=i; ++j) {
									if(mina.w>s[j].a) {
										mina.w=s[j].a;
										mina.num=j;
									}
								}
								ans+=s[i].a-mina.w+s[mina.num].c;
							}
						}
					} else {
						if(s[mina.num].b>=s[mina.num].c) {
							if(s[i].c>s[i].a-mina.w+s[mina.num].b) {
								sum.c++;
								minc.w=min(minc.w,s[i].c);
								if(minc.w==s[i].c)minc.num=i;
								ans+=s[i].c;
							} else {
								sum.b++;
								minb.w=min(minb.w,s[mina.num].b);
								if(minb.w==s[mina.num].b)minb.num=mina.num;
								mina.w=s[i].a;
								mina.num=i;
								for(int j=1; j<=i; ++j) {
									if(mina.w>s[j].a) {
										mina.w=s[j].a;
										mina.num=j;
									}
								}
								ans+=s[i].a-mina.w+s[mina.num].b;
							}
						} else {
							if(s[i].c>s[i].a-mina.w+s[mina.num].c) {
								sum.c++;
								minc.w=min(minc.w,s[i].c);
								if(minc.w==s[i].c)minc.num=i;
								ans+=s[i].c;
							} else {
								sum.c++;
								minc.w=min(minc.w,s[mina.num].c);
								if(minc.w==s[mina.num].c)minc.num=mina.num;
								mina.w=s[i].a;
								mina.num=i;
								for(int j=1; j<=i; ++j) {
									if(mina.w>s[j].a) {
										mina.w=s[j].a;
										mina.num=j;
									}
								}
								ans+=s[i].a-mina.w+s[mina.num].c;
							}
						}
					}
				}

			}
			if(s[i].b>s[i].a&&s[i].b>=s[i].c) {
				if(sum.b<n/2) {
					sum.b++;
					minb.w=min(minb.w,s[i].b);
					if(minb.w==s[i].b)minb.num=i;
					ans+=s[i].b;
				} else {
					if(s[i].a>=s[i].c) {
						if(s[minb.num].a>=s[minb.num].c) {
							if(s[i].a>s[i].b-minb.w+s[minb.num].a) {
								sum.a++;
								mina.w=min(mina.w,s[i].a);
								if(mina.w==s[i].a)mina.num=i;
								ans+=s[i].a;
							} else {
								sum.a++;
								mina.w=min(mina.w,s[minb.num].a);
								if(mina.w==s[minb.num].a)mina.num=minb.num;
								minb.w=s[i].b;
								minb.num=i;
								for(int j=1; j<=i; ++j) {
									if(minb.w>s[j].b) {
										minb.w=s[j].b;
										minb.num=j;
									}
								}
								ans+=s[i].b-minb.w+s[minb.num].a;
							}
						} else {
							if(s[i].a>s[i].b-minb.w+s[minb.num].c) {
								sum.a++;
								mina.w=min(mina.w,s[i].a);
								if(mina.w==s[i].a)mina.num=i;
								ans+=s[i].a;
							} else {
								sum.c++;
								minc.w=min(minc.w,s[minb.num].c);
								if(minc.w==s[minb.num].c)minc.num=minb.num;
								minb.w=s[i].b;
								minb.num=i;
								for(int j=1; j<=i; ++j) {
									if(minb.w>s[j].b) {
										minb.w=s[j].b;
										minb.num=j;
									}
								}
								ans+=s[i].b-minb.w+s[minb.num].c;
							}
						}
					} else {
						if(s[minb.num].a>=s[mina.num].c) {
							if(s[i].c>s[i].b-minb.w+s[minb.num].a) {
								sum.c++;
								minc.w=min(minc.w,s[i].c);
								if(minc.w==s[i].c)minc.num=i;
								ans+=s[i].c;
							} else {
								sum.a++;
								mina.w=min(mina.w,s[minb.num].a);
								if(mina.w==s[minb.num].a)mina.num=minb.num;
								minb.w=s[i].b;
								minb.num=i;
								for(int j=1; j<=i; ++j) {
									if(minb.w>s[j].b) {
										minb.w=s[j].b;
										minb.num=j;
									}
								}
								ans+=s[i].b-minb.w+s[minb.num].a;
							}
						} else {
							if(s[i].c>s[i].b-minb.w+s[minb.num].c) {
								sum.c++;
								minc.w=min(minc.w,s[i].c);
								if(minc.w==s[i].c)minc.num=i;
								ans+=s[i].c;
							} else {
								sum.c++;
								minc.w=min(minc.w,s[minb.num].c);
								if(minc.w==s[minb.num].c)minc.num=minb.num;
								minb.w=s[i].b;
								minb.num=i;
								for(int j=1; j<=i; ++j) {
									if(minb.w>s[j].b) {
										minb.w=s[j].b;
										minb.num=j;
									}
								}
								ans+=s[i].b-minb.w+s[minb.num].c;
							}
						}
					}
				}
			}
			if(s[i].c>s[i].a&&s[i].c>s[i].b) {
				if(sum.c<n/2) {
					sum.c++;
					minc.w=min(minc.w,s[i].c);
					if(minc.w==s[i].c)minc.num=i;
					ans+=s[i].c;
				} else {
					if(s[i].a>=s[i].b) {
						if(s[minc.num].a>=s[minc.num].b) {
							if(s[i].a>s[i].c-minc.w+s[minc.num].a) {
								sum.a++;
								mina.w=min(mina.w,s[i].a);
								if(mina.w==s[i].a)mina.num=i;
								ans+=s[i].a;
							} else {
								sum.a++;
								mina.w=min(mina.w,s[minc.num].a);
								if(mina.w==s[minc.num].a)mina.num=minc.num;
								minc.w=s[i].c;
								minc.num=i;
								for(int j=1; j<=i; ++j) {
									if(minc.w>s[j].c) {
										minc.w=s[j].c;
										minc.num=j;
									}
								}
								ans+=s[i].c-minc.w+s[minc.num].a;
							}
						} else {
							if(s[i].a>s[i].c-minc.w+s[minc.num].b) {
								sum.a++;
								mina.w=min(mina.w,s[i].a);
								if(mina.w==s[i].a)mina.num=i;
								ans+=s[i].a;
							} else {
								sum.b++;
								minb.w=min(minb.w,s[minc.num].b);
								if(minb.w==s[minc.num].b)minb.num=minc.num;
								minc.w=s[i].c;
								minc.num=i;
								for(int j=1; j<=i; ++j) {
									if(minc.w>s[j].c) {
										minc.w=s[j].c;
										minc.num=j;
									}
								}
								ans+=s[i].c-minb.w+s[minc.num].b;
							}
						}
					} else {
						if(s[minc.num].a>=s[mina.num].b) {
							if(s[i].b>s[i].c-minc.w+s[minc.num].a) {
								sum.b++;
								minb.w=min(minb.w,s[i].b);
								if(minb.w==s[i].b)minb.num=i;
								ans+=s[i].b;
							} else {
								sum.a++;
								mina.w=min(mina.w,s[minc.num].a);
								if(mina.w==s[minc.num].a)minb.num=minc.num;
								minc.w=s[i].c;
								minc.num=i;
								for(int j=1; j<=i; ++j) {
									if(minc.w>s[j].c) {
										minc.w=s[j].c;
										minc.num=j;
									}
								}
								ans+=s[i].c-minc.w+s[minc.num].a;
							}
						} else {
							if(s[i].b>s[i].c-minc.w+s[minc.num].b) {
								sum.b++;
								minb.w=min(minb.w,s[i].b);
								if(minb.w==s[i].b)minb.num=i;
								ans+=s[i].b;
							} else {
								sum.b++;
								minb.w=min(minb.w,s[minc.num].b);
								if(minb.w==s[minc.num].b)minb.num=minc.num;
								minc.w=s[i].c;
								minc.num=i;
								for(int j=1; j<=i; ++j) {
									if(minc.w>s[j].c) {
										minc.w=s[j].c;
										minc.num=j;
									}
								}
								ans+=s[i].c-minc.w+s[minc.num].b;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


