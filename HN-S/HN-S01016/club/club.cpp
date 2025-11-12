#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][5],cnt[N];
int n;
int maxx=-1e9,gs=0,num=0;
int dfs(int i,int j){
	if(i>n){
		return 0;
	}
	if(cnt[j]>n/2){
		return 0;
	}
	int cnt1=0;
	for(int x=1;x<=3;x++){
		cnt[x]++;
		cnt1=max(cnt1,a[i][j]+dfs(i+1,x));
		cnt[x]--;
	}
	return cnt1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int maxx=-1e9;
		for(int i=1;i<=3;i++){
			cnt[i]++;
			maxx=max(maxx,dfs(1,i));
			cnt[i]--;
		}
		cout<<maxx<<endl;
	}
	return 0;
} 
