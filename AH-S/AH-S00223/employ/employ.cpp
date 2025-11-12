#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int a[N];
string s;
int n,k;
int cnt;
int ans[N];
bool vis[N];
void dfs(int r){
	if(r==n+1){
		int taotai=0,canjia=0;
		for(int i=1;i<r;i++){
			if(taotai>=a[ans[i]]||s[i-1]=='0') taotai++;
			else if(s[i-1]=='1'){
				canjia++;
			}
			if(n-taotai<k){
				return;
			}
		}
		if(canjia>=k){
			cnt++;cnt%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		ans[r]=i;
		vis[i]=1;
		dfs(r+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	bool xingzhiA=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') xingzhiA=0;
	}
	if(n<=10){
		dfs(1);
		cout<<cnt;
		return 0;
	}
	if(xingzhiA){
		for(int i=1;i<=n;i++){
			if(cnt>=a[i]) cnt++;
			else if(a[i-1]=='0') cnt++;
			cnt%=mod;
		}
		cout<<cnt;
		return 0;
	}
	
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
 */
