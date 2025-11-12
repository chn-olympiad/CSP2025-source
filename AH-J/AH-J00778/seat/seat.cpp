#include<bits/stdc++.h>
using namespace std;
int n,m,rk;
struct Node{
	int x,id;
}a[10001];
bool cmp(Node x,Node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i].id==1) rk=i;
	int h=(rk-1)/n+1;
	if(h%2==1) cout<<h<<" "<<((rk-1)%n)+1;
	else cout<<h<<" "<<n-((rk-1)%n);
	return 0;
}
