#include<bits/stdc++.h>

using namespace std;
int n,a[10005],h[10005];
long long sum=0;
void dfs(int xb, int num, int hg, int sb){
	for(int i = xb; i < sb; i++){
		if(num+a[i]>=hg) return;
		else{
			sum++;
			sum%=998244353;
			dfs(i+1,num+a[i],hg,sb);
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	h[0]=0;
	for(int i = 1; i<=n; i++){
		h[i]=a[i]+h[i-1];
	}
	int gh,ll;
	for(int i = n; i >=1; i--){
		gh=a[i]*2;
		for(int j = i; j>=1; j--){
			if(h[j]<=gh) break;
			sum++;
			sum%=998244353;
				dfs(1,0,h[j]-gh,j);
		} 
	}
	cout << sum;
	return 0;
}
