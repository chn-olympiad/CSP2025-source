#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1005],l,op;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int s;
			cin>>s;
			a[++l]=s;
		}
	}
	int x=a[1];
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==x) op=i;
	}
	int di=op/n;
	int diff=op%n;
	if(diff==0){
		if(di%2==0) cout<<di<<" 1";
		else cout<<di<<" "<<n;
	}
	else{
		if(di%2==0) cout<<di+1<<" "<<diff;
		else cout<<di+1<<" "<<n-diff+1;
	}
	return 0;
}
