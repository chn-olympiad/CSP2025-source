#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m;
struct node{
	int x,id;
}a[N];
bool cmp(node t,node y){
	return t.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			if(i%n==0)cout<<i/n<<' '<<(i/n%2?n:1);
			else cout<<i/n+1<<' '<<((i/n+1)%2?i%n:n-i%n+1);
			break;
		}
	}
	return 0;
}
