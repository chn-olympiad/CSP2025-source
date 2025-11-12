#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,wo,x,z;
	cin>>n>>m;
	z=n*m;
	int fs[n*m]={0};
	cin>>wo;
	fs[0]=wo;
	for(int i=1;i<z;i++){
		cin>>fs[i];
	}
	sort(fs,fs+z);
	for(int i=z-1;i>=0;i--){
		if(fs[i]==wo){
			x=z-i;
			break;
		}
	}
	int h,l;
	h=(x-1)/n;
	h+=1;
	l=(x+n)%n;
	if(l==0){
		l=n;
	}
	if(h%2==0){
		l=n+1-l;
	}
	cout<<h<<" "<<l;
	return 0;
}
