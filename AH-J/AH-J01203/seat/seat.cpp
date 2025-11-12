#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,x,ans=0;
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>x) ans++;
	}
	int ans1=1,ans2=1;
	while(ans--){
		if(ans1%2) ans2++;
		else ans2--;
		if(ans2==n+1) ans2=n,ans1++;
		if(ans2==0) ans2=1,ans1++;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
