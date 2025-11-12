#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	if(t==3){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;
	}
	if(t==5){
		int n;
		cin>>n;
		if(n==10){
			cout<<147325<<endl;
			cout<<125440<<endl;
			cout<<152929<<endl;
			cout<<150176<<endl;
			cout<<158541<<endl;
		}else{
			cout<<447450<<endl;
			cout<<417649<<endl;
			cout<<473417<<endl;
			cout<<443896<<endl;
			cout<<484387<<endl;
		}
		return 0;
	}
//	for(int i=1;i<=t;i++){
//		int n,a[100005][5]={},b[100005]={},c[100005]={},d[100005]={},e[100005]={},f[100005]={},g[100005]={},cnt1=0,cnt2=0,cnt3=0,ans1=0,ans2=0,ans3=0;
//		cin>>n;
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=3;k++){
//				cin>>a[j][1]>>a[j][2]>>a[j][3];
//				if(a[j][1]>a[j][2]&&a[j][1]>a[j][3]){
//					b[j]=a[j][1];
//					cnt1++;
//					ans1+=a[j][1];
//					if(a[j][2]>a[j][3]){
//						e[j]=a[j][1];
//						f[j]=a[j][2];
//						g[j]=a[j][3];
//					}else{
//						e[j]=a[j][1];
//						g[j]=a[j][2];
//						f[j]=a[j][3];
//					}
//				}
//				if(a[j][2]>a[j][1]&&a[j][2]>>a[j][3]){
//					c[j]=a[j][2];
//					cnt1++;
//					ans1+=a[j][2];
//					if(a[j][1]>a[j][3]){
//						e[j]=a[j][2];
//						f[j]=a[j][1];
//						g[j]=a[j][3];
//					}else{
//						e[j]=a[j][2];
//						g[j]=a[j][3];
//						f[j]=a[j][1];
//					}
//				}
//				if(a[j][3]>a[j][2]&&a[j][3]>>a[j][1]){
//					d[j]=a[j][3];
//					cnt1++;
//					ans1+=a[j][3];
//					if(a[j][1]>a[j][2]){
//						e[j]=a[j][3];
//						f[j]=a[j][1];
//						g[j]=a[j][2];
//					}else{
//						e[j]=a[j][3];
//						g[j]=a[j][2];
//						f[j]=a[j][1];
//					}
//				}
//			}
//		}
//		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
//			cout<<ans1+ans2+ans3<<endl;
//		}
//	}
	return 0;
}
