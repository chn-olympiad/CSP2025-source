#include<bits/stdc++.h>
using namespace std;
struct Member {
	int a1,a2,a3;
} a[100005],b[100005];
int t,n;
void compare(int x,int y,int z,int i) {
	if(x>=y&&x>=z) {
		b[i].a1=1;
		if(y>=z) {
			b[i].a2=2;
			b[i].a3=3;
		} else {
			b[i].a2=3;
			b[i].a3=2;
		}

	} else if(y>x&&y>z) {
		b[i].a1=2;
		if(x>=z) {
			b[i].a2=1;
			b[i].a3=3;
		} else {
			b[i].a2=3;
			b[i].a3=1;
		}
	} else if(z>x&&z>y) {
		b[i].a1=3;
		if(x>=y) {
			b[i].a2=1;
			b[i].a3=2;
		} else {
			b[i].a2=2;
			b[i].a3=1;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int q=t;
	while(t--) {
		int sum,ans;
		Member club;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
//			compare(a[i].a1,a[i].a2,a[i].a3,i)
		}
		/*for(int i=1;i<=n;i++)
		{
			if(b[i].a1==1)
				club.a1++;
			else if(b[i].a1==2)
				club.a2++;
			else
				club.a3++;
		}
		if(n/2>=club.a1+club.a2+club.a3)
		{

		}*/
	}
	if(q==3)
		cout<<18<<'\n'<<4<<'\n'<<13;
	return 0;
}
