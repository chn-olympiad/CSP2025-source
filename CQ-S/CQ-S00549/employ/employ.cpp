#include <bits/stdc++.h>
using namespace std;
long long n,m,pa[1000],giveup=0,offi=0,ans=0;
bool dif[1000],visited[1000];
long long mul(long long n) {
	if(n==0) return 1;
	for(long long i = n-1; i >=2;i--) n*=i;
	return n;
}
void dfs(long long day){
	if(offi>=m) {
		ans+=mul(n-day+1);
		return;
	}
	if(giveup>n-m) return;
	for(long long i = 1; i <=n;i++) {
		if(visited[i]) continue;
		visited[i]=1;
		if(dif[day]||giveup >= pa[i]) {
		    giveup++;
		    dfs(day+1);
		    giveup--;
	    }
	    else{
	    	offi++;
	    	dfs(day+1);
	    	offi--;
		}
	    visited[i]=0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	char temp;
	for(long long i =1; i <=n;i++) {
		cin>>temp;
		if(temp=='1')dif[i]=0;
		else dif[i]=1;
	}
	for(long long i =1; i <=n;i++) cin>>pa[i];
	dfs(1);
	cout<<ans%998244353<<endl;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
