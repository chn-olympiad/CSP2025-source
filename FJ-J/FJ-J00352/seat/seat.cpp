#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p[n*m];
	for(int i=0;i<n*m;i++) cin>>p[i];
	int l=p[0];
	sort(p,p+n*m);
	int x=1,y=1,k=0;
	for(int i=n*m-1;i>=0;i--){
		a[x-1][y-1]=p[i];
		if(p[i]==l){
			cout<<y<<" "<<x;
			break;
		}
		if(k==0){
			x++;
			if(x>n) y++,x--,k=1;
		}else{
			x--;
			if(x<1) y++,x++,k=0;
		}
	}
	return 0;
}