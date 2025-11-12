#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int x,y,a[105],q,w,e=0,j=0,s,f,i;
cin >> x >> y >> s;;
for (int i = 1;i <= x;i++){
	cin >> a[i];
}
w=a[1];
	for(int j=1;j<x*y;j++ ){
		if (a[j]<a[j+1]){
			q=a[j+1];
			a[j+1] = a[j];
			a[j] = q;
		}
	}
	for(int i = 1; i<=x*y;i++){
		if (a[i]) e == w;
		e = 1;
		break;
	}
	if(e/x==0){
		f=e/x;
	}
	else{
		f=e/x+i;
	}
	f=e/x+1;
	if (f%2==0){
		j=1;
	}else{
		j=x;
	}
	f=e/x+1;
	cout << f << " " << j;
    return 0;
}