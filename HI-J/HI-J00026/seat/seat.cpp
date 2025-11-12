#include<bits/stdc++.h>
using namespace std;
int n,m,wh,a[2000],w,h,q,s;
bool e(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	wh=a[1];
	sort(a+1,a+n*m+1,e);
	for(int i=1;i<=n*m;i++) if(a[i]==wh){h=i;break;}
	w=h%n;
	if(w!=0) q=h/n+1;
	else q=h/n;
	if(w==0) w=n;
	if(q%2!=0) s=w;
	else s=n+1-w;
	cout<<q<<' '<<s;
	return 0;
}
