#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int T,n,ans,cnt[3];
struct node{
	int x[3],mx,y,id;
}a[MAXN];
bool cmp(node a,node b){
	return a.y>b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x[0]>>a[i].x[1]>>a[i].x[2];
		for(int i=1;i<=n;i++){
			int mx2=-1e9;
			a[i].mx=-1e9;
			for(int j=0;j<3;j++){
				if(a[i].x[j]>a[i].mx){
					a[i].mx=a[i].x[j];
					a[i].id=j;
				}
			}
			for(int j=0;j<3;j++)if(j!=a[i].id&&a[i].x[j]>mx2)mx2=a[i].x[j];
			a[i].y=a[i].mx-mx2;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].id]<n/2){
				cnt[a[i].id]++;
				ans+=a[i].mx;
			}else ans+=a[i].mx-a[i].y;
		}
		cout<<ans<<'\n';
	}
	return 0;
}