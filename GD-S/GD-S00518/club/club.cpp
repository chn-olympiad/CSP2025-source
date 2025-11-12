#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,t;
struct di{
	int y,e,s,cnt,p1,p2;
}a[N];
bool cmp(di x,di y){
	return x.cnt>y.cnt;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int yi=0,er=0,san=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].y>>a[i].e>>a[i].s;
			if(a[i].y>=a[i].e&&a[i].e>=a[i].s) a[i].p1=1,a[i].p2=2;
			if(a[i].y>=a[i].s&&a[i].s>=a[i].e) a[i].p1=1,a[i].p2=3;
			if(a[i].e>=a[i].y&&a[i].y>=a[i].s) a[i].p1=2,a[i].p2=1;
			if(a[i].e>=a[i].s&&a[i].s>=a[i].y) a[i].p1=2,a[i].p2=3;
			if(a[i].s>=a[i].y&&a[i].y>=a[i].e) a[i].p1=3,a[i].p2=1;
			if(a[i].s>=a[i].e&&a[i].e>=a[i].y) a[i].p1=3,a[i].p2=2;
			int aaa,bbb;
			
			if(a[i].p1==1) aaa=a[i].y;
			else if(a[i].p1==2) aaa=a[i].e;
			else aaa=a[i].s;
			if(a[i].p2==1) bbb=a[i].y;
			else if(a[i].p2==2) bbb=a[i].e;
			else bbb=a[i].s;
			a[i].cnt=aaa-bbb;
		}
		sort(a+1,a+n+1,cmp);
		
//		cout<<endl<<"//////////////////"<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<a[i].cnt<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<a[i].y<<" "<<a[i].e<<" "<<a[i].s<<endl;
//		} 
//		cout<<endl<<"?????????????????"<<endl;
		
		for(int i=1;i<=n;i++){
			if(a[i].p1==1){
				if(yi<n/2){
					ans+=a[i].y;
					yi++;
				}else if(a[i].p2==2){
					ans+=a[i].e;
					er++;
				}else{
					ans+=a[i].s; 
					san++;
				}
			}else if(a[i].p1==2){
				if(er<n/2){
					ans+=a[i].e;
					er++;
				}else if(a[i].p2==1){
					ans+=a[i].y;
					yi++;
				}else{
					ans+=a[i].s; 
					san++;
				}
			}else if(a[i].p1==3){
				if(san<n/2){
					ans+=a[i].s;
					san++;
				}else if(a[i].p2==1){
					ans+=a[i].y;
					yi++;
				}else{
					ans+=a[i].e;
					er++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
