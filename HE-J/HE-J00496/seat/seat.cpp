#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[101],h[101][101],c,r,s;
bool bm(int g,int b){
	return g>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m-1,bm);
	for(c=1;c<=m;c++){
		if(c%2==0){
			for(r=n;r>=1;r--){
				h[c][r]=a[s];
				s++;
				if(a[s-1]==x){
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
		else{
			for(r=1;r<=n;r++){
				h[c][r]=a[s];
				s++;
				if(a[s-1]==x){
					cout<<c<<" "<<r;
					return 0;
				}
			}
		}
	}
	return 0;
}
