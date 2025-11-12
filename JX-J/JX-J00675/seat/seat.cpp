#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[110],aa[11][11];
int sswr(int x,double s){
	if(s!=x) return x+1;
	return x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	y=a[1];
	int w;
	sort(a+1,a+n*m+1,greater<int>() );
	for(int i=1;i<=n*m;i++){
		if(a[i]==y) {
			w=i;
			break;
		}
	}
	int l=sswr(w/n,1.0*w/n);
	int h;
	if(l%2==1){
		h=(w-(l-1)*n)%(n+1);
	}else{
		h=m-(w-(l-1)*n)%n+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
