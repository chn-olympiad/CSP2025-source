#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m;
	cin>>n>>m;
	int a[101];
	int re=n*m;
	int c;
	bool t=1;
	for(int i=1;i<=re;i++){
		cin>>a[i];
		if(t){
			c=a[i];
			t=0;
		}
	}
	int mc;
	sort(a+1,a+1+re);
	for(int i=1;i<=re;i++){
		if(c==a[i]) mc=re-i+1;
	}
	int l;
	if(mc%n>0){
		l=mc/n+1;
	}else{
		l=mc/n;
	}
	int h;
	if(l%2==0){
		h=n-(mc-(l-1)*n)+1;
	}else{
		h=mc-(l-1)*n;
	}
	cout<<l<<" "<<h;
return 0;
}
