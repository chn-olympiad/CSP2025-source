#include <bits/stdc++.h>
using namespace std;
int t,ans[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int op=1;
	while(op<=t){
		int n,a[100005][5],one=0,two=0,three=0;
		cin>>n;
		for(int i=1 ;i<=n; i++){
			for(int j=1; j<=3; j++) cin>>a[i][j];
		}
		if(n==2) {
			int y=a[1][1]+a[2][2];
			int z=a[1][1]+a[2][3];
			int b=a[1][2]+a[2][1];
			int v=a[1][2]+a[2][3];
			int x=a[1][3]+a[2][1];
			int c=a[1][3]+a[2][2];
			ans[op]=max(ans[op],z);
			ans[op]=max(ans[op],y);
			ans[op]=max(ans[op],b);
			ans[op]=max(ans[op],c);
			ans[op]=max(ans[op],v);
			ans[op]=max(ans[op],x);
		}
		op++;
	}
	for(int i=1 ;i<=t; i++) cout<<ans[i];
}
