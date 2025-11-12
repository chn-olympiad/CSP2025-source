#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+6;
int Q,n,t[4];
struct node{
	int x[4],id;
	int fi,se,ls,ca;
}a[N];
struct nodex{
	int x,id;
}yly[4];
bool cmp(node xx,node yy){
	return xx.ca<yy.ca;
}
bool cmp1(nodex xx,nodex yy){
	return xx.x<yy.x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Q;
	while(Q--){
		t[1]=t[2]=t[3]=0;
		cin>>n;
		int e[4];
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3],a[i].id=i;
			yly[1].x=a[i].x[1],yly[2].x=a[i].x[2],yly[3].x=a[i].x[3];
			yly[1].id=1,yly[2].id=2,yly[3].id=3;
			sort(yly+1,yly+4,cmp1);
			a[i].ls=yly[1].id,a[i].se=yly[2].id,a[i].fi=yly[3].id;
			t[a[i].fi]++;
		}
		int w=0,f=0;
		for(int i=1;i<=3;i++)
			if(t[i]>n/2) w=i,f=t[i]-n/2;
		if(w){
			for(int i=1;i<=n;i++){
				if(a[i].fi==w) a[i].ca=a[i].x[a[i].fi]-a[i].x[a[i].se];
				else a[i].ca=N;
			}
			sort(a+1,a+1+n,cmp);
		}
		int zzs=0;
		for(int i=1;i<=f;i++) zzs+=a[i].x[a[i].se];
		for(int i=f+1;i<=n;i++) zzs+=a[i].x[a[i].fi];
		cout<<zzs<<"\n";
	}
	return 0;
}
