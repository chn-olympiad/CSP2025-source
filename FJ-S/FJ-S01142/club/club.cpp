#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e5+5;
int n,a[N][5],cnt[5];
vector<int>g[5];
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)a[i][j]=read(),cnt[j]=0;
	}
	for(int i=1;i<=3;i++)g[i].clear(); 
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==mx){
			ans+=mx;cnt[1]++;
			g[1].push_back(max(a[i][2],a[i][3])-a[i][1]);
		}
		else if(a[i][2]==mx){
			ans+=mx;cnt[2]++;
			g[2].push_back(max(a[i][1],a[i][3])-a[i][2]);
		}
		else if(a[i][3]==mx){
			ans+=mx;cnt[3]++;
			g[3].push_back(max(a[i][1],a[i][2])-a[i][3]);
		}
	}
	int op=-1;
	if(cnt[1]>n/2)op=1;
	if(cnt[2]>n/2)op=2;
	if(cnt[3]>n/2)op=3;
	if(op==-1){
		printf("%lld\n",ans);return;
	}
	sort(g[op].begin(),g[op].end());
	reverse(g[op].begin(),g[op].end());
	int L=0;
	while(cnt[op]>n/2){
		ans+=g[op][L];L++;cnt[op]--;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;T=read();while(T--)solve();
	return 0;
}

