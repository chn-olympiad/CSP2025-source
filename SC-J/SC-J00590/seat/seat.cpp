#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
node a[110];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,ansx,ansy;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x;
	for(int i=1;i<=n*m;i++) a[i].y=i;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i].y==1){k=i;break;}
	ansx=1+(k-1)/n;
	int l=k%n;
	if(l==0) l=n;
	if(ansx%2==1) ansy=l;
	else ansy=n+1-l;
	cout<<ansx<<' '<<ansy;
	return 0;
}