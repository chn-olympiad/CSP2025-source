#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int _,n,ans;
int p[N],a[N][3],cnt[3],p1[N],p2[N],mx1[N],mx2[N];

bool cmp(int x,int y){
	return mx1[x]-mx2[x]>mx1[y]-mx2[y];
}

void solve(){
	for(int i=1;i<=n;i++)
		mx1[i]=mx2[i]=p1[i]=p2[i]=0;
	cnt[0]=cnt[1]=cnt[2]=ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2],p[i]=i;
		for(int k=0;k<3;k++)
			if(mx1[i]<a[i][k])
				mx1[i]=a[i][k],p1[i]=k;
		for(int k=0;k<3;k++)
			if(k!=p1[i]&&mx2[i]<a[i][k])
				mx2[i]=a[i][k],p2[i]=k;
	}
	sort(p+1,p+n+1,cmp);
	for(int j=1;j<=n;j++){
		int i=p[j];
		if(cnt[p1[i]]+1>n/2)
			ans+=mx2[i],cnt[p2[i]]++;
		else
			ans+=mx1[i],cnt[p1[i]]++;
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_;
	while(_--)
		solve();
	return 0;
}

