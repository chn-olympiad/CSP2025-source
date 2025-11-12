#include<bits/stdc++.h>
using namespace std;
int t,n;
struct o{
	int x,y,z,mxid;
}a[100005];
bool cmp(o x,o y){
	if(x.mxid==y.mxid){
		if(x.mxid==1)return x.x-max(x.y,x.z)<y.x-max(y.y,y.z);
		if(x.mxid==2)return x.y-max(x.x,x.z)<y.y-max(y.x,y.z);
		if(x.mxid==3)return x.z-max(x.x,x.y)<y.z-max(y.x,y.y);
	}
	return x.mxid<y.mxid;
}
void f(int x,int cnt){
	for(int i=1;i<=n;i++){
		if(cnt<=n/2)return;
		if(a[i].mxid==x){
			cnt--;
			if(a[i].mxid==1){
				if(a[i].y>a[i].z)a[i].mxid=2;
				else a[i].mxid=3;
			}else if(a[i].mxid==2){
				if(a[i].x>a[i].z)a[i].mxid=1;
				else a[i].mxid=3;
			}else{
				if(a[i].x>a[i].y)a[i].mxid=1;
				else a[i].mxid=2;
			}
		}
	}
}
int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)a[i].mxid=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)a[i].mxid=2;
			else a[i].mxid=3;
		}
		sort(a+1,a+1+n,cmp);
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(a[i].mxid==1)cnt1++;
			if(a[i].mxid==2)cnt2++;
			if(a[i].mxid==3)cnt3++;
		}
		if(cnt1>n/2)f(1,cnt1);
		if(cnt2>n/2)f(2,cnt2);
		if(cnt3>n/2)f(3,cnt3);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].mxid==1)ans+=a[i].x;
			if(a[i].mxid==2)ans+=a[i].y;
			if(a[i].mxid==3)ans+=a[i].z;
		}
		cout<<ans<<endl;
	}
	return 0;
}
