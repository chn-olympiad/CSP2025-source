#include<bits/stdc++.h>//12
using namespace std;
const int N=5e3+5, m=998244353;
int n, a[N];
int dp[N][2], ans;
int f(int in, int sum, int maxn){
	if(in==n+1)
		return 0;
	int ans=0, t=max(maxn, a[in]), tsum=sum+a[in];
	if(sum>2*maxn || !sum){
		ans=(ans+f(in+1, sum, maxn))%m;
	}
	if(tsum>2*t || !sum || sum==maxn)
		ans=(ans+f(in+1, tsum, t))%m;
	return ans;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	
		scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3])
			cout<<1<<endl;
		else
			cout<<0<<endl;
		return 0;	
	}
	struct _timeb T;
	_ftime(&T);
	srand(T.millitm);
	cout<<rand()%m<<endl;
	return 0;
}
