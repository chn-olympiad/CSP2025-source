#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,idx;
} a[110];
bool cmp(node x,node y){
	return x.v>y.v;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].idx=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].idx==1){
			cout<<x<<' '<<y<<'\n';
			return 0;
		}
		if(x%2==1) y++;
		else y--;
		if(x%2==1&&y==n+1) x++,y=n;
		if(x%2==0&&y==0) x++,y=1;
	}
	return 0;
}
