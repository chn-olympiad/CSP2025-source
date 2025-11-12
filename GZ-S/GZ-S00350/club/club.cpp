//GZ-S00350 贵州师范大学附属中学 田雨洪 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Ed{
	int f,s,th;
}a[N];
int t,n,cnt[N],cntl[N];
bool cmpl(Ed x,Ed y){
	if(x.f>y.f) return 1;
	return 0;
}
bool cmp(Ed x,Ed y){
	if(x.s>y.s) return 1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int zw=n/2,sum=0,su=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].th;
			if(a[i].th==0) sum++;
			if(a[i].s==0) su++;
		}
		if(sum==n){
			int fm=0,sm=0;
			sort(a+1,a+n+1,cmpl);
			for(int i=1;i<=zw;i++) fm+=a[i].f,cnt[i]++;
			if(su==n){
				cout<<fm<<endl;
				continue;
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=zw;i++) sm+=a[i].s,cntl[i]++;
			if(fm>sm){
				ans+=fm;
				sort(a+1,a+n+1,cmpl);
				for(int i=1;i<=n;i++){
					if(cnt[i]==0) ans+=a[i].s;
				}
				cout<<ans<<endl;
				continue;
			}
			else{
				ans+=sm;
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(cntl[i]==0) ans+=a[i].f;
				}
				cout<<ans<<endl;
				continue;
			}
		}
		if(n==2){
			ans=max({a[1].f,a[1].s,a[1].th})+max({a[2].f,a[2].s,a[2].th});
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
