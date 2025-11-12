#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int k=t;
	while(t--) {
		int n,sum=0,a1=0,b1=0,c1=0;
		cin>>n;
		if(t==k-1) {
			for(int i=1; i<=n; i++) {
				cin>>a[i]>>b[i]>>c[i];
				if(a[i]>b[i]&&a[i]>c[i]&&a1!=n/2) {
					sum+=a[i];
					a1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&b[i]>c[i]&&a1==n/2&&b1!=n/2) {
					sum+=b[i];
					b1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&c[i]>b[i]&&a1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&b[i]>c[i]&&a1==n/2&&b1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&c[i]>b[i]&&a1==n/2&&c1==n/2&&b1!=n/2) {
					sum+=b[i];
					b1++;
				}
				if(b[i]>a[i]&&b[i]>c[i]&&b1!=n/2) {
					sum+=b[i];
					b1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&a[i]>c[i]&&b1==n/2&&a1!=n/2) {
					sum+=a[i];
					a1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&c[i]>a[i]&&b1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&a[i]>c[i]&&b1==n/2&&a1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&c[i]>a[i]&&b1==n/2&&c1==n/2&&a1!=n/2) {
					sum+=a[i];
					a1++;
				}
				if(c[i]>a[i]&&c[i]>b[i]&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&a[i]>b[i]&&c1==n/2&&a[i]!=n/2) {
					sum+=a[i];
					a1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&b[i]>a[i]&&c1==n/2&&b[i]!=n/2) {
					sum+=b[i];
					b1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&a[i]>b[i]&&c1==n/2&&a[i]==n/2&&b1!=n/2) {
					sum+=b[i];
					b1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&b[i]>a[i]&&c1==n/2&&b[i]==n/2&&a1!=n/2) {
					sum+=a[i];
					a1++;
				}
			}
		} else {
			int x,y,z;
			for(int i=1; i<=n; i++) {
				cin>>x>>y>>z;
				a[i]=x;
				b[i]=y;
				c[i]=z;
				if(a[i]>b[i]&&a[i]>c[i]&&a1!=n/2) {
					sum+=a[i];
					a1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&b[i]>c[i]&&a1==n/2&&b1!=n/2) {
					sum+=b[i];
					b1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&c[i]>b[i]&&a1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&b[i]>c[i]&&a1==n/2&&b1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(a[i]>b[i]&&a[i]>c[i]&&c[i]>b[i]&&a1==n/2&&c1==n/2&&b1!=n/2) {
					sum+=b[i];
					b1++;
				}
				if(b[i]>a[i]&&b[i]>c[i]&&b1!=n/2) {
					sum+=b[i];
					b1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&a[i]>c[i]&&b1==n/2&&a1!=n/2) {
					sum+=a[i];
					a1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&c[i]>a[i]&&b1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&a[i]>c[i]&&b1==n/2&&a1==n/2&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(b[i]>a[i]&&b[i]>c[i]&&c[i]>a[i]&&b1==n/2&&c1==n/2&&a1!=n/2) {
					sum+=a[i];
					a1++;
				}
				if(c[i]>a[i]&&c[i]>b[i]&&c1!=n/2) {
					sum+=c[i];
					c1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&a[i]>b[i]&&c1==n/2&&a[i]!=n/2) {
					sum+=a[i];
					a1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&b[i]>a[i]&&c1==n/2&&b[i]!=n/2) {
					sum+=b[i];
					b1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&a[i]>b[i]&&c1==n/2&&a[i]==n/2&&b1!=n/2) {
					sum+=b[i];
					b1++;
				} else if(c[i]>a[i]&&c[i]>b[i]&&b[i]>a[i]&&c1==n/2&&b[i]==n/2&&a1!=n/2) {
					sum+=a[i];
					a1++;
				}
			}

		}
		cout<<sum<<endl;
	}
    fclose(in); 
    fclose(out);
    return 0;
}
