#include<bits/stdc++.h>
using namespace std;
const int maxn = 104;
struct node{
	int x,index;
}a[maxn];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].index=i;
	sort(a+1,a+1+n*m,cmp);
	int l,r;
	for(int i=1;i<=n*m;i++){
		r=(i-1)/n+1;
		if(r&1) l=i-(r-1)*n;
		else l=n-(i-(r-1)*n)+1;
		if(a[i].index==1){
			cout<<r<<" "<<l<<"\n";
			break; 
		}
	}
	return 0;
}
