#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,ans,cd,d[N],a[N][3],cnt[3],ch[N];
void solve(){
	scanf("%d",&n);
	cnt[0]=cnt[1]=cnt[2]=0;
	ans=0;
	for(int i=1,j;i<=n;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		j=max({a[i][0],a[i][1],a[i][2]});
		ans+=j;
		if(a[i][0]==j) cnt[0]++,ch[i]=0;
		else if(a[i][1]==j) cnt[1]++,ch[i]=1;
		else cnt[2]++,ch[i]=2;
	}
	if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
		printf("%d\n",ans);
		return ;
	}
	int id;
	if(cnt[0]>n/2) id=0;
	else if(cnt[1]>n/2) id=1;
	else id=2;
	cd=0;
	for(int i=1;i<=n;i++){
		if(ch[i]==id){
			int mx=-2e9;
			for(int j=0;j<3;j++){
				if(j!=id) mx=max(mx,a[i][j]-a[i][id]);
			}
			d[++cd]=mx;
		}
	}
	sort(d+1,d+cd+1,greater<int>());
	for(int i=1;i<=cnt[id]-n/2;i++) ans+=d[i];
	printf("%d\n",ans);
}
int main(){
//	system("fc club.out club5.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0; 
}
