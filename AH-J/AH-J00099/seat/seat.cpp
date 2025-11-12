#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	int id;
	int d;
}a[1005];
bool cmp (node xx,node yy){
	return xx.d>yy.d;
}
int main (){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,x;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].d;
		a[i].id=i;
	}
	sort (a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i].id==1) {
			x=i;
			break;
		}
	}
	//cout<<x<<endl;
	if ((x-1)/n%2==0) cout<<(x-1)/n+1<<" "<<(x-1)%n+1<<endl;
	else cout<<(x-1)/n+1<<" "<<n-((x-1)%n+1)+1<<endl;
	return 0;
}
