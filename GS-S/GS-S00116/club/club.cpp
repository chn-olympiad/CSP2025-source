#include<bits\stdc++.h>
using namespace std;
long long rs,t,a[10005],b[10005],c[10005],ss[5],n,maxx;
void dfs(long long st,long long sum) {
	if(st>n) {
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1; i<=3; i++) {
		if(ss[i]+1<=n/2) {
			ss[i]++;
			if(i==1) {
				dfs(st+1,sum+a[st]);
			}
			if(i==2) {
				dfs(st+1,sum+b[st]);
			}
			if(i==3) {
				dfs(st+1,sum+c[st]);
			}
			ss[i]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		maxx=0;
		ss[1]=0;
		ss[2]=0;
		ss[3]=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0);
		cout<<maxx<<"\n";
	}
	return 0;

}
