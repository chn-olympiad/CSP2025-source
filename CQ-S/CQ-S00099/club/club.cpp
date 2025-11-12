#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],cnt[5],len[5],q[5][100005],p[100005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=len[1]=len[2]=len[3]=0;
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,ans+=a[i][1],q[1][++len[1]]=i;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,ans+=a[i][2],q[2][++len[2]]=i;
			else cnt[3]++,ans+=a[i][3],q[3][++len[3]]=i;
			sort(a[i]+1,a[i]+4);
		}
		int idx;
		if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3]) idx=1;
		else if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3]) idx=2;
		else idx=3;
		if(cnt[idx]<=(n/2)){
			cout<<ans<<"\n";
			continue;
		}
		long long rst=cnt[idx]-n/2,l=0;
		for(int i=1;i<=len[idx];i++){
			int x=q[idx][i];
			int now=a[x][3]-a[x][2];
			p[++l]=now;
		}
		sort(p+1,p+l+1);
		for(int i=1;i<=rst;i++) ans-=p[i];
		cout<<ans<<"\n";
	}
	return 0;
}
