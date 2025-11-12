#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5;
const int MAXN=200005;
int n;
int cnt[MAXM];
int b[MAXN];
int a[MAXN][MAXM]; 
int id[MAXM][MAXN];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxn=max({a[i][1],a[i][2],a[i][3]});
			ans+=maxn;
			if(maxn==a[i][1]){
				id[1][++cnt[1]]=i;
			}else if(maxn==a[i][2]){
				id[2][++cnt[2]]=i;
			}else{
				id[3][++cnt[3]]=i;
			}
		}
		int k=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				k=i;
				break;
			}
		}
		for(int i=1;i<=cnt[k];i++){
			int v=id[k][i];
			bool f=0;
			int maxc=0;
			int maxn=max({a[v][1],a[v][2],a[v][3]});
			for(int j=1;j<=3;j++){
				if(f==0&&a[v][j]==maxn){
					f=1;
				}else{
					maxc=max(maxc,a[v][j]);
				}
			}
			b[++sum]=(maxn-maxc);
		}
		sort(b+1,b+sum+1);
		for(int i=1;i<=cnt[k]-n/2;i++){
			ans-=b[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}
