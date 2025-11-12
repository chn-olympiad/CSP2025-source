#include<bits/stdc++.h>
using namespace std;
struct tt {
	int department;
	int pr;
};
struct zz {
	tt p[4];
	int flag=0;
} a[100005] ;
bool cmp(tt x,tt y) {
	if(x.pr<y.pr)
		return false;
	else
		return true;
}
bool cmp1(zz x,zz y) {
	if(x.flag==0 and y.flag==0)
		if(x.p[1].pr<y.p[1].pr)
			return false;
		else if(x.p[1].pr==y.p[1].pr and x.p[2].pr<y.p[2].pr)//loading
			return false;
		else
			return true;
	else if(x.flag==0 and y.flag!=0)
		return false;
	else return true;
}
bool cmp2(zz x,zz y) {
	if(x.flag==0 and y.flag==0)
		if(x.p[2].pr<y.p[2].pr)
			return false;
		else if(x.p[2].pr==y.p[2].pr and x.p[3].pr<y.p[3].pr)//loading
			return false;
		else
			return true;
	else if(x.flag==0 and y.flag!=0)
		return false;
	else return true;
}
bool cmp3(zz x,zz y) {
	if(x.flag==0 and y.flag!=0)
		return false;
	else return true;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		long long n,ans=0;
		cin>>n;
		int most=n/2;
		for(int i=1; i<=n; i++) {
			cin>>a[i].p[1].pr>>a[i].p[2].pr>>a[i].p[3].pr;
			a[i].p[1].department=1;
			a[i].p[2].department=2;
			a[i].p[3].department=3;
			sort(a[i].p+1,a[i].p+4,cmp);
		}
		int d1=0,d2=0,d3=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1; i<=n; i++) {
			if(a[i].p[1].department==1 && d1<n/2)ans+=a[i].p[1].pr,d1++,a[i].flag=1;
			if(a[i].p[1].department==2 && d2<n/2)ans+=a[i].p[1].pr,d2++,a[i].flag=1;
			if(a[i].p[1].department==3 && d3<n/2)ans+=a[i].p[1].pr,d3++,a[i].flag=1;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1; i<=n; i++) {
			if(a[i].flag==1)break;
			if(a[i].p[2].department==1 && d1<n/2)ans+=a[i].p[2].pr,d1++,a[i].flag=1;
			if(a[i].p[2].department==2 && d2<n/2)ans+=a[i].p[2].pr,d2++,a[i].flag=1;
			if(a[i].p[2].department==3 && d3<n/2)ans+=a[i].p[2].pr,d3++,a[i].flag=1;
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1; i<=n; i++) {
			if(a[i].flag==1)break;
			if(a[i].p[3].department==1 && d1<n/2)ans+=a[i].p[3].pr,d1++;
			if(a[i].p[3].department==2 && d2<n/2)ans+=a[i].p[3].pr,d2++;
			if(a[i].p[3].department==3 && d3<n/2)ans+=a[i].p[3].pr,d3++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
