#include<bits/stdc++.h>
using namespace std;

int t,n;
long long ans;
long long a[100005][5];

void dfs(int al,int b,int c,int step,long long value) {
	if(step>n) {
		ans=max(ans,value);
		return;
	}
	if(al+1<=n/2){
		dfs(al+1,b,c,step+1,value+a[step][1]);
	}
	if(b+1<=n/2){
		dfs(al,b+1,c,step+1,value+a[step][2]);
	}
	if(c+1<=n/2){
		dfs(al,b,c+1,step+1,value+a[step][3]);
	}	
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++) {
		ans=-1;
		cin>>n;
		for(int j=1; j<=n; j++) {
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
