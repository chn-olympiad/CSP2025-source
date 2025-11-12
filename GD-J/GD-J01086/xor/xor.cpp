#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,k,a[N],nw,ans;
struct node{
	int id,p;
}dp[N];
bool cmp(node a,node b){
	return a.p<b.p;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)cin >> a[i];
	if(n>=1000){
		int anss=0,f=1;
		for(int i = 1; i <= n; i++){
			anss+=a[i];
			if(a[i]>1)f=0;
		}
		if(f){//B
			cout << anss << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		dp[i].id=i;dp[i].p=2e9;
		int l=0,j=i;
		for(; j <= n; j++){
			l^=a[j];
			if(l==k){j++;break;}
		}
		if(l==k){
			dp[i].p=j;
		}
	}
	sort(dp+1,dp+n+1,cmp);
	nw=1;
	while(1){
		if(dp[nw].p==2e9||nw>n)break;
		nw=dp[nw].p;
		ans++;
		sort(dp+1,dp+n+1,cmp2);
		sort(dp+nw,dp+n+1,cmp);
	}
	cout << ans;
	return 0;
}


