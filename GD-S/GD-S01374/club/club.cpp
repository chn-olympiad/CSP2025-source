#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans=0;
int cha[N][2];
int a[N][4];
int cnt[4];
void pt(int x) {
	int maxx=-1,maxx2=-1,zuobiao=0;
	for(int i=1;i<=3;i++) {
		if(a[x][i]>maxx) maxx2=maxx,maxx=a[x][i],zuobiao=i;
		else if(a[x][i]>maxx2) maxx2=a[x][i];
	}
	ans=ans+maxx;
	cha[x][1]=maxx-maxx2;
	cha[x][0]=zuobiao;
	cnt[zuobiao]++;
}
int num[N],Cnt=0;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t--) {
		int duo=0; 
		cin>>n;
		ans=0;
		Cnt=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			pt(i);
		}
		if(cnt[1]>n/2) {
			for(int i=1;i<=n;i++) if(cha[i][0]==1) {
				num[++Cnt]=cha[i][1];
			} 
			duo=cnt[1]-n/2;
		}
		if(cnt[2]>n/2) {
			for(int i=1;i<=n;i++) if(cha[i][0]==2) {
				num[++Cnt]=cha[i][1];
			} 
			duo=cnt[2]-n/2;
		}
		if(cnt[3]>n/2) {
			for(int i=1;i<=n;i++) if(cha[i][0]==3) {
				num[++Cnt]=cha[i][1];
			} 
			duo=cnt[3]-n/2;
		}
		sort(num+1,num+Cnt+1);
		for(int i=1;i<=duo;i++) ans=ans-num[i];
		cout<<ans<<"\n";
	}
}
