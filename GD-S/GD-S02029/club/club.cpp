#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[10005],mx[100005];
int t,n;
bool f() {
	for(int i=1; i<=n; i++) {
		if(0!=c[i]|| 0!=b[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		
		cin>>n;
		int sum=0;
		int x=0,y=0,z=0;
		for(int i=1; i<=n; i++) {
			//cout<<"µÚ"<<i<<"¸ö";
			cin>>a[i]>>b[i]>>c[i];
			if( a[i]>=c[i] && a[i]>=b[i]) {
				mx[i]=1;
				x++;
			} else if(b[i]>=c[i]&&b[i]>=a[i]) {
				mx[i]=2;
				y++;
			} else {
				mx[i]=3;
				z++;
			}
		}
		//*
		if(f()) {
			sort(a,a+n);
			for(int i=n; i>=n/2; i--) {
				sum+=a[i];
			}
			cout<<sum;
		} else if(max(z,max(x,y))<=n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i]>=max(c[i],b[i])) {
					sum+=a[i];
				} else if(b[i]>=max(c[i],a[i])) {
					sum+=b[i];
				} else {
					sum+=c[i];
				}
			}
			cout<<sum<<endl;;
		} else {
			//*/
			cout<<max( a[1]+b[2],max( a[1]+c[2],max( b[1]+a[2],max( b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))))<<endl;;

		}
	}
	return 0;
}/*

4
4 2 1
7 2 4
5 3 4
3 5 1
*/
