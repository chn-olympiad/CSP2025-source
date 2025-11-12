#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node {
	int a1,a2,a3;
} a[100009];
int ca[100009][4];
bool cmptemp(node x,node y) {
	return x.a1>y.a1;
}
int dp[300][4][300];
int pd(int x) {
	if(a[x].a1>a[x].a2&&a[x].a1>a[x].a3) {
		return 1;
	}
	if(a[x].a2>a[x].a1&&a[x].a2>a[x].a3) {
		return 2;
	}
	if(a[x].a3>a[x].a1&&a[x].a3>a[x].a2) {
		return 3;
	}
}
int pd2(int x) {
	if(a[x].a1>a[x].a2&&a[x].a2>a[x].a3||a[x].a3>a[x].a2&&a[x].a2>a[x].a1) {
		return 2;
	}
	if(a[x].a2>a[x].a1&&a[x].a1>a[x].a3||a[x].a3>a[x].a1&&a[x].a1>a[x].a2) {
		return 1;
	}
	if(a[x].a1>a[x].a3&&a[x].a3>a[x].a2||a[x].a2>a[x].a3&&a[x].a3>a[x].a1) {
		return 3;
	}
}
long long ans = 0;
int pr[4];
void dfs(int xb,int cb,long long num){
	if(xb>n){
		ans = max(ans,num);
		return;
	}
	pr[cb]++;
	if(pr[1]<n/2){
		dfs(xb+1,1,num+ca[xb+1][1]);
	}
	if(pr[2]<n/2){
		dfs(xb+1,2,num+ca[xb+1][2]);
	}
	if(pr[3]<n/2){
		dfs(xb+1,3,num+ca[xb+1][3]);
	}
	pr[cb]--;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans = 0; 
		cin>>n;
		bool Aflag = 0;
		bool Bflag = 0;
		for(int i = 1; i<=n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a3!=0) {
				Bflag = 1;
				Aflag = 1;
			}
			if(a[i].a2 !=0) {
				Aflag = 1;
			}
			ca[i][1] = a[i].a1;
			ca[i][2] = a[i].a2;
			ca[i][3] = a[i].a3;
		}
		if(!Aflag) {
			sort(a+1,a+n+1,cmptemp);
			for(int i = 1; i<=n/2; i++) {
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n == 2) {
			int maxn = pd(1);
			int maxm = pd(2);
			if(maxn == maxm) {
				ans = max(ca[1][maxn]+ca[2][pd2(2)],ca[1][pd2(1)]+ca[2][maxm]);
			} else {
				ans = ca[1][maxn]+ca[2][maxm];
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,1,ca[1][1]);
		dfs(1,2,ca[1][2]);
		dfs(1,3,ca[1][3]);
		cout<<ans<<endl;
	}
	return 0;
}


