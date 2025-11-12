#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int xh=a[1];
	sort(a+1,a+n*m+1);reverse(a+1,a+n*m+1);
	int pos;
	for(int i=1;i<=n*m;i++) if(a[i]==xh) pos=i;
	int p=pos/n,c=p,r;
	if(pos%n) c++;
	if(c%2){
		if(pos%n) r=pos%n;
		else r=n;
	}else{
		if(pos%n) r=n-pos%n+1;
		else r=1;
	}
	cout<<c<<" "<<r;
}
