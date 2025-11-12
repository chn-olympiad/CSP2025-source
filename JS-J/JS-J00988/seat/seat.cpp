#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],pos;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			pos=i;
			break;
		}
	}
	int dx=(pos-1)/n+1,dy;
	if(dx%2==1)dy=pos-(dx-1)*n;
	else dy=n-(pos-(dx-1)*n)+1;
	cout<<dx<<" "<<dy;
	return 0;
}
