//#include <bits/stdc++.h>
//using namespace std;
//const int N=1e5+10;
//int T,n,ans;
//struct node{
//	int s1,s2,s3,mx;
//}a[N],b[N];
//bool cmp1(node x1,node x2){
//	if(x1.s1==x2.s1&&x1.s2==x2.s2) return x1.s3>x2.s3;
//	if(x1.s1==x2.s1) return x1.s2>x2.s2;
//	return x1.s1<x2.s1;
//}
//bool cmp2(node x1,node x2){
////	if(x1.s2==x2.s2&&x1.s1==x2.s1) return x1.s3>x2.s3;
////	if(x1.s2==x2.s2) return x1.s1>x2.s1;
//	return x1.s2<x2.s2;
//}
//bool cmp3(node x1,node x2){
//	if(x1.s3==x2.s3&&x1.s2==x2.s2) return x1.s1>x2.s1;
//	if(x1.s3==x2.s3) return x1.s2>x2.s2;
//	return x1.s3<x2.s3;
//}
//int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	cin>>T;
//	while(T--){
//		cin>>n;
//		int p1=0,p2=0,p3=0,p_mx=n/2;
//		ans=0;
//		for(int i=1;i<=n;i++){
//			cin>>a[i].s1>>a[i].s2>>a[i].s3;
//			if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3) a[i].mx=1;
//			if(a[i].s2>=a[i].s1&&a[i].s2>=a[i].s3) a[i].mx=2;
//			if(a[i].s3>=a[i].s1&&a[i].s3>=a[i].s2) a[i].mx=3;
//		}
////  1
////	2
////  10 9 8
////  4 0 0
//		sort(a+1,a+1+n,cmp1);
//		for(int i=1;i<=n;i++){
//			if(p1<p_mx&&a[i].mx==1){
//				p1++;ans+=a[i].s1;
//			}else if(p2<p_mx&&a[i].mx==2){
//				p2++;ans+=a[i].s2;
//			}else if(p3<p_mx&&a[i].mx==3){
//				p3++;ans+=a[i].s3;
//			}
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans;
int p_mx;
struct node{
	int s1,s2,s3;
}a[N];
bool cmp(node x1,node x2){
	if(x1.s1==x2.s1) return x1.s2>x2.s2;
	return x1.s1<x2.s1;
}
void fs(int ds,int sum,int p1,int p2,int p3){
	if(ds>n||p1>p_mx||p2>p_mx||p3>p_mx) return;
	if(ds==n) ans=max(ans,sum);
	if(a[ds+1].s1==a[ds+1].s2||a[ds+1].s1==a[ds+1].s3)fs(ds+1,sum+a[ds+1].s1,p1+1,p2,p3);
	if(a[ds+1].s2==a[ds+1].s3)fs(ds+1,sum+a[ds+1].s2,p1,p2+1,p3);
	else{
		fs(ds+1,sum+a[ds+1].s1,p1+1,p2,p3);
		fs(ds+1,sum+a[ds+1].s2,p1,p2+1,p3);
		fs(ds+1,sum+a[ds+1].s3,p1,p2,p3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;p_mx=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
		}
		sort(a+1,a+1+n,cmp);
		fs(0,0,0,0,0);
		cout<<ans<<endl;
	} 
}
