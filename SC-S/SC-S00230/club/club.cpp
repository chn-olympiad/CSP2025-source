#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct node{
	int x,y,z;
}a[100005];
bool cmp(node a,node b){
	int a1=max(a.x,max(a.y,a.z));
	int a3=min(a.x,min(a.y,a.z));
	int a2;
	if(a.x<=a1&&a.x>=a3) a2=a.x;
	else if(a.y<=a1&&a.y>=a3) a2=a.y;
	else a2=a.z;
	int b1=max(b.x,max(b.y,b.z));
	int b3=min(b.x,min(b.y,b.z));
	int b2;
	if(b.x<=b1&&b.x>b3) b2=b.x;
	else if(b.y<=b1&&b.y>=b3) b2=b.y;
	else b2=b.z;
	if(a1==b1){
		if(a2==b2){
			return a3>b3;
		}
		return a2>b2;
	}
	return a1>b1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt[4],sum=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int fi;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) fi=1;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) fi=2;
			else fi=3;
			if(cnt[fi]<n/2){
				cnt[fi]++;
				if(fi==1) sum+=a[i].x;
				else if(fi==2) sum+=a[i].y;
				else sum+=a[i].z;
			}
			else{
				int se,th;
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&a[i].y>=a[i].z) se=2,th=3;
				else if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&a[i].y<=a[i].z) se=3,th=2;
				else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&a[i].x>=a[i].z) se=1,th=3;
				else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&a[i].x<=a[i].z) se=3,th=1;
				else if(a[i].x>=a[i].y) se=1,th=2;
				else se=2,th=1;
				if(cnt[se]<n/2){
					cnt[se]++;
					if(se==1) sum+=a[i].x;
					else if(se==2) sum+=a[i].y;
					else sum+=a[i].z;
				}
				else{
					cnt[th]++;
					if(th==1) sum+=a[i].x;
					else if(th==2) sum+=a[i].y;
					else sum+=a[i].z;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
