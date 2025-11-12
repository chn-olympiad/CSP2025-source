#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct node{
	int id,x;
}a[105];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) s=i;
	}
	if((s-1)/n%2==0) cout<<(s-1)/n+1<<' '<<(s-1)%n+1;
	else cout<<(s-1)/n+1<<' '<<n-(s-1)%n;
	return 0;
}
