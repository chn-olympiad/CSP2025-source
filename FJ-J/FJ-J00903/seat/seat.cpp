#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	int a[n*m+1];
	int s=1;
	cin >> n >> m;
	int h=n,g=n*m;
	for(int i=1;i<=g;i++){
		cin >> a[i];
		if(a[1]<a[i]){
			s++;
		}
	}
	if(s%h==0){
		c=s/h;
	}else{
		c=s/h+1;
	}
	if(c%2==1){
		r=s%h;
		if(r==0){
			r=r+h;
		}
	}else{
		r=h-(s%h-1);
		if(r>h){
			r=r-h;
		}
	}
	cout << c << " " << r;
	return 0;
}
