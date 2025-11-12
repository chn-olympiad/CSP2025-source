#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1],num=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==k) num=n*m-i+1;
	int s=(num-1)/n;
	if(s%2==0) cout<<s+1<<' '<<(num%n?num%n:n);
	else cout<<s+1<<' '<<(num%n?n-num%n+1:1);
	return 0;
}
