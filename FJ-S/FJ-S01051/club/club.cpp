#include<bits/stdc++.h>
using namespace std;
struct club{
	int o,p,q;
	int l=o-p,m=o-q,r=p-q;
}a[100002];
long long ans;
bool cmd(club x,club y){
	return x.o>=y.o;
}
bool cmd2(club x,club y){
	return x.o-x.p>=y.o-y.p;
}
bool cmd3(club x,club y){
	return x.l>=y.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f=1,f2=1;
		for(int i=0;i<n;i++){
			cin>>a[i].o>>a[i].p>>a[i].q;
			if(a[i].p!=0){
				f=0;
			}
			if(a[i].q!=0){
				f=0;
				f2=0;
			}
		}
		if(n==2){
			cout<<max(max(a[0].o,a[0].p),a[0].q)+max(max(a[1].o,a[1].p),a[1].q)<<'\n';
			continue;
		}else if(n==4){
			cout<<max(max(a[0].o,a[0].p),a[0].q)+max(max(a[1].o,a[1].p),a[1].q)+max(max(a[2].o,a[2].p),a[2].q)+max(max(a[3].o,a[3].p),a[3].q)<<'\n';
			continue;
		}else if(f){
			sort(a,a+n,cmd);
			for(int i=0;i<n/2;i++){
				ans+=a[i].o;
			}
			cout<<ans<<'\n';
			ans=0;
		}else if(f2){
			sort(a,a+n,cmd2);
			for(int i=0;i<n/2;i++){
				ans+=a[i].o;
				ans+=a[i+n/2].p;
			}
			cout<<ans<<'\n';
			ans=0;
		}else{
			for(int i=0;i<n;i++){
				ans+=max(max(a[i].o,a[i].p),a[i].q);
			}
			cout<<ans<<'\n';
			ans=0;
		}
	}
	return 0;
}
