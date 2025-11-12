#include<bits/stdc++.h>
using namespace std;
int n,m,num=1,a,b,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)
			num++;
	}
	l=num/n+1;
	h=num%n;
	if(h==0){
		l--;
		h=n;
	}
	if(l%2==0)
		h=n-h+1;
	cout<<l<<' '<<h;
	return 0;
}