#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct p{
	int d1,d2,d3,t;
};
int t,n;
p a[maxn];
bool cmp1(p x,p y){
	if(x.t!=1)return 0;
	if(y.t!=1)return 1;
	return (x.d1-max(x.d2,x.d3))>(y.d1-max(y.d2,y.d3));
}
bool cmp2(p x,p y){
	if(x.t!=2)return 0;
	if(y.t!=2)return 1;
	return (x.d2-max(x.d1,x.d3))>(y.d2-max(y.d1,y.d3));
}
bool cmp3(p x,p y){
	if(x.t!=3)return 0;
	if(y.t!=3)return 1;
	return (x.d3-max(x.d2,x.d1))>(y.d3-max(y.d2,y.d1));
}
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
				a[i].t=1;
				cnt1++;
			}
			if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
				a[i].t=2;
				cnt2++;
			}
			if(a[i].d3>=a[i].d2&&a[i].d3>=a[i].d1){
				a[i].t=3;
				cnt3++;
			}
		}
		if(cnt1>n/2){
			sort(a+1,a+n+1,cmp1);
			for(int i=n/2+1;i<=cnt1;i++){
				if(a[i].d2>a[i].d3)a[i].t=2;
				else a[i].t=3;
			}
		}
		if(cnt2>n/2){
			sort(a+1,a+n+1,cmp2);
			for(int i=n/2+1;i<=cnt2;i++){
				if(a[i].d1>a[i].d3)a[i].t=1;
				else a[i].t=3;
			}
		}if(cnt3>n/2){
			sort(a+1,a+n+1,cmp3);
			for(int i=n/2+1;i<=cnt3;i++){
				if(a[i].d2>a[i].d1)a[i].t=2;
				else a[i].t=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].t==1){
				ans+=a[i].d1;
			}
			if(a[i].t==2){
				ans+=a[i].d2;
			}
			if(a[i].t==3){
				ans+=a[i].d3;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
