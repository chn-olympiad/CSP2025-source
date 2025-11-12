#include<bits/stdc++.h>
using namespace std;
int t,n,maxx,sum1,sum2,sum3,ans;
struct road{
	int a,b,c;
}d[100005];
bool cmp(road x,road y) {
	return -(x.a+x.b+x.c-min(min(x.a,x.b),min(x.b,x.c)))+2*max(max(x.a,x.b),max(x.b,x.c)) > -(y.a+y.b+y.c-min(min(y.a,y.b),min(y.b,y.c)))+2*max(max(y.a,y.b),max(y.b,y.c));
}
void c1() {
	ans+=maxx;
	sum1++;
}
void c2() {
	sum2++;
	ans+=maxx;
}
void c3() {
	sum3++;
	ans+=maxx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		sum1=0,sum2=0,sum3=0,ans=0;
		memset(d,0,sizeof(d));
		for(int i = 1;i <= n;i++) 
			cin >> d[i].a >> d[i].b >> d[i].c;
		sort(d+1,d+n+1,cmp);
		for(int i = 1;i <= n;i++) {
			maxx=max(max(d[i].a,d[i].b),max(d[i].b,d[i].c));
			if(maxx == d[i].a && sum1 < n/2) c1();
			else if(maxx == d[i].b && sum2 < n/2) c2();
			else if(maxx == d[i].c && sum3 < n/2) c3();
			else {
				int mam=min(min(d[i].a,d[i].b),min(d[i].b,d[i].c));
				if(d[i].a != maxx && d[i].a != mam && sum1 < n/2) {
					sum1++; ans+=d[i].a;
				}
				else if(d[i].b != maxx && d[i].b != mam && sum2 < n/2) {
					sum2++; ans+=d[i].b;
				}
				else if(d[i].c != maxx && d[i].c != mam && sum3 < n/2) {
					sum3++; ans+=d[i].c;
				}
				else {
					if(sum1 < n/2) {
						sum1++; ans+=d[i].a;
					}
					else if(sum2 < n/2) {
						sum2++; ans+=d[i].b;
					}
					else if(sum3 < n/2) {
						sum3++; ans+=d[i].c;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
