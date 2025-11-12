#include<bits/stdc++.h>
#define MAXN 114514
using namespace std;
int dp[MAXN][3];
int arr[MAXN][3];
int n;
int pex1[MAXN],pex2[MAXN],pex3[MAXN];
int dfs(int a,int b,int c,int i) {
	if (i>n) return 0;
	int ans=0;
	if (a>=n/2) {
		return pex1[i];
	} else if (b>=n/2) {
		return pex2[i];
	} else if (c>=n/2) {
		return pex3[i];
	} else {
		ans=max({ans,dfs(a+1,b,c,i+1)+arr[i][1],dfs(a,b+1,c,i+1)+arr[i][2],dfs(a,b,c+1,i+1)+arr[i][3]});
	}
	
	return ans;
}
vector<int> acc;
bool cmp(int a,int b) {
	return a>b;
}
void slove()
{
	cin>>n;
	bool ck1=1,ck2=1;
	for(int i=1;i<=n;i++) {
		cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
		pex1[i]=pex2[i]=pex3[i]=0;
		acc.push_back(arr[i][1]);
		if (arr[i][2]!=0 || arr[i][3]!=0) ck1=0;
		if (arr[i][3]!=0) ck2=0;
	}
	
	if (ck1) {
		acc.clear();
		int ans=0;
		sort(acc.begin(),acc.end(),cmp);
		for(int i=1;i<=n/2;i++) {
			ans+=acc[i];
		}
		cout<<ans<<endl;
		return;
	}
	pex1[n+1]=pex2[n+1]=pex3[n+1]=0;
	for(int i=n;i>=1;i--) {
		pex1[i]=pex1[i+1]+max(arr[i][2],arr[i][3]);
		pex2[i]=pex2[i+1]+max(arr[i][1],arr[i][3]);
		pex3[i]=pex3[i+1]+max(arr[i][2],arr[i][1]);
	}
	cout<<dfs(0,0,0,1)<<endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		slove();
	}
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1

*/
