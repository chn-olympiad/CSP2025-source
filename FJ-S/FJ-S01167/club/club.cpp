#include<bits/stdc++.h>
using namespace std;
int t,n;
struct q{
	int l1,l2,l3,a1,a2,a3,c1,c2,e;
};
int maxa(int a,int b,int c){
	if(a>b&&a>c) return a;
	if(b>a&&b>c) return b;
	return c;
}
int maxb(int a,int b,int c){
	if(a>b&&a<c||a>c&&a<b) return a;
	if(b>a&&b<c||b>c&&b<a) return b;
	return c;
}
int maxc(int a,int b,int c){
	if(a<b&&a<c) return a;
	if(b<a&&b<c) return b;
	return c;
}
bool cmp(q a,q b){
	return a.c1<b.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0,x=0,y=0,z=0;
		q a[100010];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			int aa=maxa(a[i].l1,a[i].l2,a[i].l3),bb=maxb(a[i].l1,a[i].l2,a[i].l3),cc=maxc(a[i].l1,a[i].l2,a[i].l3);
			if(aa==a[i].l1){
				x++;
				a[i].e=1;
			}else if(aa==a[i].l2){
				y++;
				a[i].e=2;
			}else{
				z++;
				a[i].e=3;
			}
			a[i].c1=aa-bb;
			a[i].c2=bb-cc;
		}
		if(x>n/2){
			sort(a,a+n,cmp);
		}
		for(int i=0;i<n;i++){
			if(a[i].e==1) ans+=a[i].l1;
			else if(a[i].e==2) ans+=a[i].l2;
			else ans+=a[i].l3;
		}
		cout<<ans;
	}
	return 0;
}
