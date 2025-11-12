#include<bits/stdc++.h>
using namespace std;
long long qwe[5010];
long long n;
long long ans=0;
void go(long long x,long long as,long long mx,long long op) {
	if(x>n) {
		if(as>2*mx&&op>2)
			ans++;
		return;
	}
	go(x+1,as+qwe[x],max(qwe[x],mx),op+1);
	go(x+1,as,mx,op);
}
int main() {
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++)
		cin>>qwe[i];
	go(1,0,0,0);
	cout<<ans<<endl;
}
