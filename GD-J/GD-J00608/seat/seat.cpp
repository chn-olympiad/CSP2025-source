#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n,m,s,y,p=1,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n*m-1;i++){
		cin>>y;
		if(y>s){
			p++;
		}
	}
	if(p%n==0){
		l=p/n;
	}
	else{
		l=p/n+1;
	}
	if(l%2==1){
		h=p%m;
		if(h==0){
			h=n;
		}
	}
	else{
		h=n-((p+1)%n);
	}
	cout<<l<<" "<<h;
}
