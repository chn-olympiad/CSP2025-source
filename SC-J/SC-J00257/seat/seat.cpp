#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,xx,mc;
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xx=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xx){
			mc=i;
		}
	}
	int ll=(mc+n-1)/n;
	int hh;
	if(ll%2){
		if(mc%n){
			hh=mc%n;
		}
		else{
			hh=n;
		}
	}
	else{
		if(mc%n){
			hh=n+1-mc%n;
		}
		else{
			hh=1;
		}
	}
	cout<<ll<<' '<<hh;
	return 0;
} 