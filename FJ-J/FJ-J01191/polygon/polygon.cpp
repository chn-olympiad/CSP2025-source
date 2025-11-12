#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5,m = 998244353;
int n,cnt=0,a[maxn];
bool vis[maxn];
//vector<int> ans;
void dfs(int pos,int c,long long sum,int maxx){
	if(c >= 3 && sum > maxx*2){
//		for(auto i:ans) cout << i << " ";
//		cout << "aaa";
//		cout << sum << " " << maxx << endl;
		cnt++;
		cnt%=m;
	}
	for(int i=pos+1;i<=n;i++){
		if(vis[i] == 0){
			vis[i] = 1;
//			ans.push_back(a[i]);
			dfs(i,c+1,sum+a[i],max(maxx,a[i]));
//			ans.pop_back();
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,0);
	printf("%d",cnt);
	return 0; 
} 
