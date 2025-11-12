#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 100005
#define int long long
#define PII pair<int,int>
using namespace std;
int T,n;
PII a[N][5];
struct node{
	int v,ot,id;
}b[N];
int c[N],tot;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=tot;i++)
			c[i]=0;
		tot=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].first;
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+3+1,greater<PII>());
			b[i].v=a[i][1].first;
			b[i].id=a[i][1].second;
			b[i].ot=a[i][1].first-a[i][2].first;
		}
		int cnt[5]={0,0,0,0,0};
		int ans=0;
		for(int i=1;i<=n;i++){
			cnt[b[i].id]++;
			ans+=b[i].v;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		int idx=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]>n/2)
				idx=i;
		for(int i=1;i<=n;i++)
			if(b[i].id==idx)
				c[++tot]=b[i].ot;
		sort(c+1,c+tot+1);
		for(int i=1;i<=cnt[idx]-n/2;i++)
			ans-=c[i];
		cout<<ans<<'\n';
	}
	return 0;
}
