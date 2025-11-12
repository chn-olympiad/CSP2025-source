#include<bits/stdc++.h>
using namespace std;
const int N=11;
int n,m,a[N*N],his,pos,px,py;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	his=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==his){
			pos=n*m-i+1;
			break;
		}
	}
	px=(pos%n?pos/n+1:pos/n);
	if(px&1) py=pos-(px-1)*n;
	else py=m-(pos-(px-1)*n)+1;
	cout<<px<<' '<<py;
	return 0;
}