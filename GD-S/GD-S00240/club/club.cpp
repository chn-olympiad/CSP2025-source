#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],d[205][205][205],g,ans,f,fl,b[100005],mi[100005],qw[5],ma[100005];
int vis[100005];
struct sr{
	int x,y,z;
}c[300005];
bool cmp(sr qw, sr we){
	if(qw.x!=we.x) return qw.x>we.x;
	if(qw.y!=we.y) return qw.y<we.y;
	return qw.z<we.z;
}
//struct qwq{
//	int x,y;
//};
priority_queue<int> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) mi[i]=1e9,ma[i]=0;
		for(int j=1;j<=n;j++) for(int l=1;l<=3;l++){
			cin>>a[j][l];
			if(l==2) f+=a[j][l];
			if(l==3) fl+=a[j][l];
			mi[j]=min(mi[j],a[j][l]);
			ma[j]=max(ma[j],a[j][l]);
		}
		ans=0;
		if(n<=200){
			for(int j=1;j<=n;j++) for(int l=0;l<=n;l++) for(int k=0;k<=n;k++) d[j][l][k]=0;
			for(int j=1;j<=n;j++) for(int l=0;l<=min(n/2,j);l++) for(int k=0;k<=min(n/2,j-l);k++){
				int p=j-l-k;
				if(p<=n/2){
					if(l) d[j][l][k]=d[j-1][l-1][k]+a[j][1];
					if(k) d[j][l][k]=max(d[j-1][l][k-1]+a[j][2],d[j][l][k]);
					if(p) d[j][l][k]=max(d[j-1][l][k]+a[j][3],d[j][l][k]);
					if(j==n) ans=max(ans,d[j][l][k]);
//					cout<<j<<" "<<l<<" "<<k<<" "<<p<<" "<<d[j][l][k]<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
		else if(f==0&&fl==0){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n,g=n/2;i>=1&&g;i--,g--){
				ans+=b[i];
			}
			cout<<ans<<"\n";
		}
		else {
			for(int i=1;i<=n;i++){
				ans+=ma[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
