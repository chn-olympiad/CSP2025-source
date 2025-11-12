#include <bits/stdc++.h>
using namespace std;
int q,w,e,r[105],p,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>w>>e;
	for(int i=0;i<w*e;i++){
		cin>>r[i];
	}
	p=r[0];
	sort(r,r+w*e);
	for(int i=w*e-1;i>=0;i--){
		if(r[i]==p){
			p=w*e-i;
		}
	}
	a=p/e;
	if(p%e!=0){
		a+=1;
	}
	cout<<a<<" ";
	if(a%2==0){
		cout<<e-p%e+1;
		return 0;
	}
	else{
		if(p%e==0){
			cout<<e;
			return 0;
		}
		else{
			cout<<p%e;
			return 0;
		}
	}
	return 0;
}
