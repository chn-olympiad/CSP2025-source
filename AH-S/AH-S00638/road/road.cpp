#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005],b[15];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cin>>b[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)ans+=a[i];
	cout<<ans;
	return 0;
}
