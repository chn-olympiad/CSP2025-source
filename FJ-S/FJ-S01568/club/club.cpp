#include<bits/stdc++.h>
using namespace std;
struct msz{
	int id=-1,m;
}dpa[100005],dpb[100005],dpc[100005];
bool cmp(msz x,msz y){
	return x.m>y.m;
}
int n,a[100005][4],t;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	
	while(T--){
	int aa=0,bb=0;
	for(int i=0;i<=100005;i++){
		dpa[i].id=-1;dpa[i].m=-1;
		dpb[i].id=-1;dpa[i].m=-1;
		dpc[i].id=-1;dpa[i].m=-1;
	}
	t=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
//		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
//			dpa[aa].id=i;
			dpa[i].m=a[i][1];
			t+=a[i][1];
//			aa++;
//		}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
//			dpb[bb].id=i;
//			dpb[bb].m=a[i][2];
//			t+=a[i][2];
//			bb++;
//		}
//		else{
//			dpc[i].id=i;
//			dpc[i].m=a[i][3];
//			t+=a[i][3];
//		}
	}
	
	sort(dpa,dpa+n,cmp);
//	sort(dpb,dpb+bb,cmp);
//	sort(dpc,dpc+n,cmp);
	
	for(int i=0;i<n;i++){
		if(i>n/2){
			//t+=max(a[dpa[i].id][2],a[dpa[i].id][3])-dpa[i].m;
			t-=/*a[dpa[i].id][2]-*/dpa[i].m;
//			cout<<t<<" ";
		}
	}
	t-=dpa[n-1].m;
//	cout<<t<<'\n';
//	for(int i=0;i<bb,dpb[i].id!=-1;i++){
//		if(i>n/2){
//			t+=a[dpb[i].id][1]-dpb[i].m;
////			cout<<t<<"b ";
//		}
//	}
//	cout<<t<<'\n';
//	for(int i=0;i<n,dpc[i].id!=-1;i++){
//		if(i>n/2){
//			t+=max(a[dpc[i].id][1],a[dpc[i].id][2])-dpc[i].m;
//			cout<<t<<"c ";
//		}
//	}
//	
	cout<<t<<'\n';
	}
	return 0;
}
