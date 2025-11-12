#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int hang,lei;
	cin>>hang>>lei;
	long long b=hang*lei;
	int a[b];
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+b+1);
	int c;
	for(int i=b;i>0;i--){
		if(a[i]==a1){
			c=b-i+1;
			break;
		}
	}
	int x,y;
	int d;
	if(c%hang==0){
		d=c/hang;
	}else{
		d=c/hang+1;
	}
	if(d%2!=0){
		if(c%hang!=0){
			x=c/hang+1;
		}else{
			x=c/hang;
		}
		if(c%hang==0){
			y=hang;
		}else{
		y=c-c/hang*hang;
		}
	}else{
		if(c%hang!=0){
			x=c/hang+1;
		}else{
			x=c/hang;
		}
		y=hang-c%hang+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
