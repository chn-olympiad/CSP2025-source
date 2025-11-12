#include<bits/stdc++.h>
using namespace std;
long long A[100010],B[100010],C[100010],Max;
void dfs(int x,int cnt1,int cnt2,int cnt3,int n,long long ans){
	if(x == n + 1){
		Max = max(Max,ans);
		return ;
	}
	if(cnt1 < (n / 2))dfs(x + 1,cnt1 + 1,cnt2,cnt3,n,ans + A[x]);
	if(cnt2 < (n / 2))dfs(x + 1,cnt1,cnt2 + 1,cnt3,n,ans + B[x]);
	if(cnt3 < (n / 2))dfs(x + 1,cnt1,cnt2,cnt3 + 1,n,ans + C[x]);
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		memset(A,0,sizeof(0));
		memset(B,0,sizeof(0));
		memset(C,0,sizeof(0));
		Max = 0;
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)cin >> A[i] >> B[i] >> C[i];
		dfs(1,0,0,0,n,0);
		cout << Max << endl;
	}
	
	return 0;
} 
