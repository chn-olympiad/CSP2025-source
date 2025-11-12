#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node {
	int a[5];
	int c[5];
	int q;
} s[N];
int t;
bool cmp1(node a,node b) {
	return a.c[1]<b.c[1];
}
bool cmp2(node a,node b) {
	return a.c[2]<b.c[2];
}
bool cmp3(node a,node b) {
	return a.c[3]<b.c[3];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int ans=0;
		int s1=0,s2=0,s3=0;
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
			s[i].c[1]=s[i].a[1]-s[i].a[2];
			s[i].c[2]=s[i].a[2]-s[i].a[3];
			s[i].c[3]=s[i].a[3]-s[i].a[1];
			int mx=INT_MIN;
			mx=max(s[i].a[1],max(s[i].a[2],s[i].a[3]));
			ans+=mx;
			if(s[i].a[1]==mx) {
				s[i].q=1;
			} else if(s[i].a[2]==mx) {
				s[i].q=2;
			} else {
				s[i].q=3;
			}
		}
		for(int i=1; i<=n; i++) {
			if(s[i].q==1) {
				s1++;
			} else if(s[i].q==2) {
				s2++;
			} else {
				s3++;
			}
		}
		while(s1>n/2) {
			s1--;
			sort(s+1,s+n+1,cmp1);
			ans-=s[1].c[1];
			s[1].q=2;
			s2++;
			while(s2>n/2) {
				s2--;
				sort(s+1,s+n+1,cmp2);
				ans-=s[1].c[2];
				s[1].q=3;
				s3++;
				while(s3>n/2) {
					s3--;
					sort(s+1,s+n+1,cmp3);
					ans-=s[1].c[3];
					s[1].q=1;
					s1++;
				}
			}
		}
		while(s1>n/2) {
			s1--;
			sort(s+1,s+n+1,cmp1);
			ans-=s[1].c[1];
			s[1].q=2;
			s2++;
			while(s3>n/2) {
				s3--;
				sort(s+1,s+n+1,cmp3);
				ans-=s[1].c[3];
				s[1].q=1;
				s1++;
				while(s2>n/2) {
					s2--;
					sort(s+1,s+n+1,cmp2);
					ans-=s[1].c[2];
					s[1].q=3;
					s3++;
				}
			}
		}
		while(s2>n/2) {
			s2--;
			sort(s+1,s+n+1,cmp2);
			ans-=s[1].c[2];
			s[1].q=3;
			s3++;
			while(s1>n/2) {
				s1--;
				sort(s+1,s+n+1,cmp1);
				ans-=s[1].c[1];
				s[1].q=2;
				s2++;
				while(s3>n/2) {
					s3--;
					sort(s+1,s+n+1,cmp3);
					ans-=s[1].c[3];
					s[1].q=1;
					s1++;
				}
			}
		}
		while(s2>n/2) {
			s2--;
			sort(s+1,s+n+1,cmp2);
			ans-=s[1].c[2];
			s[1].q=3;
			s3++;
			while(s3>n/2) {
				s3--;
				sort(s+1,s+n+1,cmp3);
				ans-=s[1].c[3];
				s[1].q=1;
				s1++;
				while(s1>n/2) {
					s1--;
					sort(s+1,s+n+1,cmp1);
					ans-=s[1].c[1];
					s[1].q=2;
					s2++;
				}
			}
		}
		while(s3>n/2) {
			s3--;
			sort(s+1,s+n+1,cmp3);
			ans-=s[1].c[3];
			s[1].q=1;
			s1++;
			while(s2>n/2) {
				s2--;
				sort(s+1,s+n+1,cmp2);
				ans-=s[1].c[2];
				s[1].q=3;
				s3++;
				while(s1>n/2) {
					s1--;
					sort(s+1,s+n+1,cmp1);
					ans-=s[1].c[1];
					s[1].q=2;
					s2++;

				}
			}
		}
		while(s3>n/2) {
			s3--;
			sort(s+1,s+n+1,cmp3);
			ans-=s[1].c[3];
			s[1].q=1;
			s1++;
			while(s1>n/2) {
				s1--;
				sort(s+1,s+n+1,cmp1);
				ans-=s[1].c[1];
				s[1].q=2;
				s2++;

				while(s2>n/2) {
					s2--;
					sort(s+1,s+n+1,cmp2);
					ans-=s[1].c[2];
					s[1].q=3;
					s3++;

				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
