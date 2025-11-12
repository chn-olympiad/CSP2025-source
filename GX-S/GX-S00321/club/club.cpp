#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
const ll iii=2e9+10;
struct node{
	int x,y,z;
} a[N];
int t,n;
ll sum,cnt,ppt,ans;
bool cmpx(node p,node q){
	return p.x>q.x;
}
bool cmpy(node p,node q){
	return p.y>q.y;
}
int cntA,cntB;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0,cntA=0,cntB=0,ppt=0;
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0&&a[i].z==0) cntA++;
			if(a[i].z==0) cntB++;
		}
		if(cntA==n){
			sort(a+1,a+n+1,cmpx);
			for(int i=1;i<=n/2;i++) sum+=a[i].x;
			cout<<sum<<"\n";
		}else if(cntB==n&&cntA<n){
			sort(a+1,a+n+1,cmpx);
			for(int i=1;i<=n/2;i++) sum+=a[i].x;
			for(int i=n/2+1;i<=n;i++) sum+=a[i].y;
			sort(a+1,a+n+1,cmpy);
			for(int i=1;i<=n/2;i++) ppt+=a[i].y;
			for(int i=n/2+1;i<=n;i++) ppt+=a[i].x;
			ans=max(sum,ppt0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
