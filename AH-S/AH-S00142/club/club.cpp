#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,xx[100005],yy[100005],zz[100005],ans,xxx,yyy,zzz,qwq[200005];
struct no{
	int x,y,z,i;
}a[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=xxx=yyy=zzz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].i=i;
		}
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)xx[++xxx]=a[i].i;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)yy[++yyy]=a[i].i;
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)zz[++zzz]=a[i].i;
		}
		if(xxx<=n/2&&yyy<=n/2&&zzz<=n/2){
			for(int i=1;i<=n;i++)ans+=max(a[i].x,max(a[i].y,a[i].z));
			cout<<ans<<'\n';
		}else{
			memset(qwq,0,sizeof qwq);
			if(xxx>n/2){
				//cout<<'x'<<endl;
				ans=0;
				for(int i=1;i<=yyy;i++)ans+=a[yy[i]].y;
				for(int i=1;i<=zzz;i++)ans+=a[zz[i]].z;
				for(int i=1;i<=xxx;i++){
					int now=xx[i];
					ans+=a[now].x;
					qwq[i]=min(a[now].x-a[now].y,a[now].x-a[now].z);
					//cout<<xx[i]<<" "<<qwq[i]<<endl;
				}
				sort(qwq+1,qwq+xxx+1);
				for(int i=1;i<=xxx-n/2;i++)ans-=qwq[i];
			}else if(yyy>n/2){
				//cout<<'y'<<endl;
				ans=0;
				for(int i=1;i<=xxx;i++)ans+=a[xx[i]].x;
				for(int i=1;i<=zzz;i++)ans+=a[zz[i]].z;
				for(int i=1;i<=yyy;i++){
					int now=yy[i];
					ans+=a[now].y;
					qwq[i]=min(a[now].y-a[now].x,a[now].y-a[now].z);
					//cout<<yy[i]<<" "<<qwq[i]<<endl;
				}
				sort(qwq+1,qwq+yyy+1);
				for(int i=1;i<=yyy-n/2;i++)ans-=qwq[i];
			}else{
				//cout<<'z'<<endl;
				ans=0;
				for(int i=1;i<=xxx;i++)ans+=a[xx[i]].x;
				for(int i=1;i<=yyy;i++)ans+=a[yy[i]].y;
				for(int i=1;i<=zzz;i++){
					int now=zz[i];
					ans+=a[now].z;
					qwq[i]=min(a[now].z-a[now].x,a[now].z-a[now].y);
					//cout<<zz[i]<<" "<<qwq[i]<<endl;
				}
				sort(qwq+1,qwq+zzz+1);
				for(int i=1;i<=zzz-n/2;i++)ans-=qwq[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
