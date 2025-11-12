#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100005;
int a[N][10],bel[N],cnt[10];
bool flag[N];
pair<int,int> b[N*10];
void work(){
	int n,m=3;
	cin>>n;
	for(int i=1;i<=m;i++) cnt[i]=0;
	LL ans=0;
	for(int i=1;i<=n;i++){
		flag[i]=0;
		int p=1;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>a[i][p]) p=j;
		}
		cnt[p]++;
		ans+=a[i][p];
		bel[i]=p;
	}
	int mp=1;
	for(int i=1;i<=m;i++){
		if(cnt[i]>cnt[mp]) mp=i;
	}
	if(cnt[mp]<=n/2){
		cout<<ans<<'\n';
		return;
	}
	int dc=cnt[mp]-n/2;
	int tot=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(bel[i]==mp&&j!=mp) b[++tot]={a[i][mp]-a[i][j],i};
	}
	sort(b+1,b+tot+1);
	for(int i=1;i<=tot&&dc;i++){
		if(flag[b[i].second]) continue;
		dc--;
		flag[b[i].second]=1;
		ans-=b[i].first;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) work();
	return 0;
}