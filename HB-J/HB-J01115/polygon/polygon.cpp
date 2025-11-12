#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long sum,maxn=-0xffffffff,cnt;
void dfs(int k,int m){
	if(k>=3 and sum>maxn*2){
		cnt++;
		return;
	}
	if(k>=n) return;
	sum+=m;
	if(m>maxn) maxn=m;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			k++;
			dfs(k,a[i]);
			b[i]=0;
			k--;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
		if(a[i]>maxn) maxn=a[i];
	}
	if(n<3){
		cout << 0%998244353;
		return 0;
	}
	else if(sum<=maxn*2){
		cout << 0%998244353;
		return 0;
	}
	if(n==3){
		cout << 1%998244353;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0);
	cout << cnt%998244353;
	return 0;
}
