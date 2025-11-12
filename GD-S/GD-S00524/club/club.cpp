#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,a1,a2,a3;
struct yf{
	long long x,y,z,pot,up;
}a[600000];
bool cmp(yf aaa,yf bbb){
	return aaa.pot>bbb.pot;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		a1=0;
		a2=0;
		a3=0;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			long long uup=min({a[i].x,a[i].y,a[i].z}),down=max({a[i].x,a[i].y,a[i].z});
			if(a[i].x!=uup&&a[i].x!=down){
				a[i].up=a[i].x;
			}else if(a[i].y!=uup&&a[i].y!=down){
				a[i].up=a[i].y;
			}else if(a[i].z!=uup&&a[i].z!=down){
				a[i].up=a[i].z;
			}else if(a[i].x==a[i].y){
				a[i].up=a[i].x;
			}else if(a[i].z==a[i].y){
				a[i].up=a[i].z;
			}else{
				a[i].up=a[i].x;
			}
//			cout<<a[i].up<<"EDFW"<<endl;
			ans+=a[i].up;
			a[i].pot=down-a[i].up;
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].x<<a[i].y<<a[i].z<<endl;
//		}
		for(long long i=1;i<=n;i++){
			if(a[i].x==max({a[i].x,a[i].y,a[i].z})){
				if(a1<(n/2)){
					ans+=a[i].pot;
					a1++;
//					cout<<a[i].pot+a[i].up<<"kk"<<endl;
				}
			}else if(a[i].y==max({a[i].x,a[i].y,a[i].z})){
				if(a2<(n/2)){
					ans+=a[i].pot;
					a2++;
//					cout<<a[i].pot+a[i].up<<"kk"<<endl;
				}
			}else{
				if(a3<(n/2)){
					ans+=a[i].pot;
					a3++;
//					cout<<a[i].pot+a[i].up<<"kk"<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
}
////10
//2020 14533 18961
////2423 15344 16322
//1910 6224 16178
//2038 9963 19722
////8375 10557 5444
//3518 14615 17976
////6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926
