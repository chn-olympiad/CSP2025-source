#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,tot=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(s<a)tot++;
	}
	int ans1=(tot+n-1)/n;
	int ans2=(tot-1)%n+1;
	cout<<ans1<<" ";
	if(ans1%2==0)cout<<m-ans2+1;
	else cout<<ans2;
	return 0;
}