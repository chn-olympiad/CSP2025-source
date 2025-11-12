#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],k=1;
void read(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//竖着的是n，横着的是m。
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])k++;
	}		
	int h,l;
	l=ceil(1.0*k/n);
	h=k%n;
	if(h==0)h=n;
	if(!(l&1)){
		h=n-h+1;
	}	
	cout<<l<<" "<<h;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	read();
	
	return 0;
}