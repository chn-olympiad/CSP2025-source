#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int x;
	int pos;
}x[4],a[100005],b[100005];
bool z[100005];
int pos[100005];
bool cmp(node x,node y) {
	return x.x>y.x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		memset(z,false,sizeof(z));
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				scanf("%d",&x[j].x);
				x[j].pos=j;
			}
			sort(x+1,x+4,cmp);
			a[i].x=x[1].x;
			a[i].pos=x[1].pos;
			b[i].x=x[2].x;
			b[i].pos=x[2].pos;
		}
		int cnt[4]={0,0,0,0};
		int ans=0;
		int minn=0x3f3f3f3f,po=0;
		for(int i=1;i<=n;i++) {
			if(cnt[a[i].pos]<n/2) {
				ans+=a[i].x;
				cnt[a[i].pos]++;
				z[i]=1;
				pos[i]=a[i].pos;
				if(a[i].x-b[i].x<minn) {
					minn=a[i].x-b[i].x;
					po=i;
				}
			}
			else {
				if(ans+b[i].x>ans-minn+a[i].x) {
					cnt[b[i].pos]++;
					z[i]=false;
					pos[i]=b[i].pos;
				}
				else {
					z[po]=false;
					pos[po]=b[po].pos;
					pos[i]=a[i].pos;
					z[i]=true;
				}
				ans=max(ans+b[i].x,ans-minn+a[i].x);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
