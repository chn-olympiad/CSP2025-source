#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],pos,rx,ry;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pos=n*m+1-i;
		}
	}
	rx=(pos-1)/n+1;
	if(rx%2!=0){
		ry=pos-(rx-1)*n;
	}else{
		ry=n+1-(pos-(rx-1)*n);
	}
	cout<<rx<<" "<<ry<<endl;
	return 0;
}
