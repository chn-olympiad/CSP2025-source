#include<bits/stdc++.h>
using namespace std;
int T;
struct Node {
	int a,b,c;
} a[100005];
int al,bl,cl,n;
int b[100005];
int c[100005];
int d[100005];
long long ans;
bool cmp(int e,int f) {
	return e>f;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			c[i]=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a>a[i].b&&a[i].a>a[i].c) {
				al++;
				d[i]=1;
				b[i]=a[i].a-max(a[i].b,a[i].c);
			} else if(a[i].b>a[i].a&&a[i].b>a[i].c) {
				bl++;
				d[i]=2;
				b[i]=a[i].b-max(a[i].a,a[i].c);
			} else {
				cl++;
				d[i]=3;
				b[i]=a[i].c-max(a[i].a,a[i].b);
			}
		}
		if(al>n/2||bl>n/2||cl>n/2) {
			sort(b+1,b+n+1,cmp);
			int k=0;
			if(al>n/2) {
				for(int i=1; i<=n; i++) {
					if(d[i]==1) {
						if(k==n/2) {
							ans+=c[i]-b[i];
						} else {
							ans+=c[i];
							k++;
						}

					} else {
						ans+=c[i];
					}
				}
			} else if(bl>n/2) {
				for(int i=1; i<=n; i++) {
					if(d[i]==2) {
						if(k==n/2) {
							ans+=c[i]-b[i];
						} else {
							ans+=c[i];
							k++;
						}

					} else {
						ans+=c[i];
					}
				}
			} else if(cl>n/2) {
				for(int i=1; i<=n; i++) {
					if(d[i]==3) {
						if(k==n/2) {
							ans+=c[i]-b[i];
						} else {
							ans+=c[i];
							k++;
						}

					} else {
						ans+=c[i];
					}
				}
			}
		} else {
			for(int i=1; i<=n; i++) {
				ans+=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
