#include<bits/stdc++.h>
using namespace std;
long n,m,a[90010],cnt=0;
bool t[90010];
void dfs(long k,long x,long s,long m,long y) {
	if(k>=x) {
		if(s>m*2) {
			cnt++;
		}
		return;
	}
	for(long i=y+1; i<=n; i++) {
		if(t[i]==false) {
			t[i]=true;
			long temp=s+a[i];
			long mx=max(m,a[i]);
			dfs(k+1,x,temp,mx,i);
			t[i]=false;
		} 
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long l=3; l<=n; l++) {
		dfs(0,l,0,0,0);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
