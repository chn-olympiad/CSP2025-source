#include<bits/stdc++.h>
using namespace std;
const int N=120;
int n,m,x;
struct node{int z,o;}a[N];
bool cmp(node&q,node&w){return q.z>w.z;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].z,a[i].o=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(a[i].o==1)x=i;
	int ans=(x+n-1)/n;
	cout<<ans<<' '<<(ans%2?(x%n?x%n:n):n-(x%n?x%n:n)+1)<<"\n";
	return 0;
}
