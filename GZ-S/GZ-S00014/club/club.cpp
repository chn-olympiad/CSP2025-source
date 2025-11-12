// GZ-S00014 代玲聪 安顺市第一中学
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define sc scanf
using namespace std;
const int N=1e5+10;
inline int in() {
	char ch=getchar();
	int w=1,s=0;
	while(ch>'9'||ch<'0') {
		if(ch=='-')w*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
int a[N],b[N],c[N],d[N];
int cnt1,cnt2,cnt3;
int n,t;
//int ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	//cin >> t ;
	while(t--) {
		n=in();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));

		//cin >> n ;
		int tmp=n/2;
		for(int i=1; i<=n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		for(int i=1;i<=n;i++){
			
			if(a[i]>b[i]&&a[i]>c[i]) {
				if(cnt1<=tmp) {

					d[i]=a[i];
					cnt1++;
				} 
				else if(cnt1>tmp) {
					if(cnt2<=tmp) {
						if(b[i]>c[i]) {
							d[i]=b[i];
							cnt2++;
						} else {
							d[i]=c[i];
							cnt3++;
						}
					} else {
						d[i]=c[i];
						cnt3++;
					}
				}

			}
			else if(b[i]>a[i]&&b[i]>c[i]) {
				if(cnt2<=tmp) {

					d[i]=b[i];
					cnt2++;
				} 
				else if(cnt2>tmp) {
					if(cnt1<=tmp) {
						if(a[i]>c[i]) {
							d[i]=a[i];
							cnt1++;
						} else {
							d[i]=c[i];
							cnt3++;
						}
					} else {
						d[i]=c[i];
						cnt3++;
					}
				}
			}
			else if(c[i]>a[i]&&c[i]>b[i]) {
				if(cnt3<=tmp) {

					d[i]=c[i];
					cnt3++;
				} 
				else if(cnt3>tmp) {
					if(cnt2<=tmp) {
						if(b[i]>a[i]) {
							d[i]=b[i];
							cnt2++;
						} else {
							d[i]=a[i];
							cnt1++;
						}
					} else {
						d[i]=a[i];
						cnt2++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
		//	cout << d[i] << " ";
			ans+=d[i];
		}
		//	cout << endl;
		printf("%d\n",ans);
	}
	return 0;

}
