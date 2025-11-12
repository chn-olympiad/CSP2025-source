#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{int x,id;}a[105];
bool cmp(node x,node y){return x.x>y.x;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i].id==1){
			int p=(i-1)/n+1;
			int q=(i-1)%n+1;
			if(p&1) cout<<p<<' '<<q; 
			else cout<<p<<' '<<n-q+1;
		}
	}
}
