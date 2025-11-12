#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,a1[N],a2[N],a3[N],n,ans1,ans2,ans3;
struct sb {
	int yh,id,k1,k2;
} k[N];
int anser() {
	int yy=0,kk[2]= {0,0};
	for(int i=1; i<=n; i++) {
		if(i<=n/2) yy+=k[i].k1;
		else {
			for(int j=i; j<=n; j++) yy+=k[i].k2;
			break;
		}
	}
	return yy;
}
bool cmp(sb x,sb y) {
	return x.yh>y.yh;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		for(int i=1; i<=n; i++) {
			k[i].yh=a1[i]-max(a2[i],a3[i]);
			k[i].k1=a1[i];
			k[i].k2=max(a2[i],a3[i]);
			if(a2[i]>a3[i]) k[i].id=0;
			else if(a2[i]<a3[i]) k[i].id=1;
			else k[i].id=2;
		}
		sort(k+1,k+1+n,cmp);
		ans1=anser();
		for(int i=1; i<=n; i++) {
			k[i].yh=a2[i]-max(a1[i],a3[i]);
			k[i].k1=a2[i];
			k[i].k2=max(a1[i],a3[i]);
			if(a1[i]>a3[i]) k[i].id=0;
			else if(a1[i]<a3[i]) k[i].id=1;
			else k[i].id=2;
		}
		sort(k+1,k+1+n,cmp);
		ans2=anser();
		for(int i=1; i<=n; i++) {
			k[i].yh=a3[i]-max(a1[i],a2[i]);
			k[i].k1=a3[i];
			k[i].k2=max(a1[i],a2[i]);
			if(a1[i]>a2[i]) k[i].id=0;
			else if(a1[i]<a2[i]) k[i].id=1;
			else k[i].id=2;
		}
		sort(k+1,k+1+n,cmp);
		ans3=anser();
		cout<<max(ans1,max(ans2,ans3))<<endl;
	}
	return 0;
}