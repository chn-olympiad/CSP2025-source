#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,p,pb[10000]={},m=0;
	cin>>h>>l;
	p=h*l;
	for(int a=0;a<p;a++){
		cin>>pb[a];	
	}
	int r=pb[0];
	sort(pb,pb+p);
	for(int a=0;a<p;a++){
		if(pb[a]==r) {
		m=a+1;
		break;
		}
	}
	m=p-m+1;
	int hh=0,ll=0;
	int rh=m%h;
	if(rh==0) ll=m/3;
	else ll=m/3+1;
	
	cout<<ll<<' ';
	if(ll%2==1) {
		if(rh==0)cout<<l;
		else cout<<rh;
	}
	else {
		if(rh==0) cout<<1;
		else cout<<h-rh+1;
	}
	fclose(stdin);
	fclose(stdout);
}
