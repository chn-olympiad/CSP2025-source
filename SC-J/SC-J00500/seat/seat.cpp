#include<bits/stdc++.h>
using namespace std;
int m,n,a[1001],s,mc=1,h,l,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	d=m*n;
	for(int i=1;i<=d;i++){
		cin>>a[i];
		if(i==1)s=a[i];
		if(a[i]>s)mc++;
	}
	if(mc%m==0)l=mc/m;
	else l=mc/m+1;
	h=mc%m;
	if(l%2==1){
		if(h==0)h=m;
	}
	else{
		if(h==0)h=1;
		else h=m+1-h;
	}
	cout<<l<<" "<<h;
	return 0;
}