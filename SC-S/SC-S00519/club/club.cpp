#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 100005

int T;
int n;
int a[MAXN][4];
int cnt[4];
vector<int> cost;
int ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		cost.clear();
		cin>>n;
		int flag=0;
		for(int i=1;i<=n;i++){
			int maxn=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][maxn]<a[i][j]) maxn=j;
			}
			cnt[maxn]++;
			ans+=a[i][maxn];
			if(cnt[maxn]>n/2) flag=maxn;
		}
		if(!flag){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int maxn=0;
			for(int j=1;j<=3;j++){
				if(j==flag) continue;
				maxn=max(maxn,a[i][j]);
			}
			if(maxn>a[i][flag]) continue;
			cost.push_back(a[i][flag]-maxn);
		}
		sort(cost.begin(),cost.end());
		for(int i=0;i<cnt[flag]-n/2;i++){
			ans-=cost[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}