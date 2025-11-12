#include<bits/stdc++.h>
using namespace std;
int e[10000004],w[1000002];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,jl,j,d;
	cin>>n>>m;
	int u=n*m;
	for(int i=1;i<=u;i++){
		cin>>w[i];
}
	jl=w[1];
	sort(w,w+u+1);
	d=1;
	for(int i=n*m;i>0;i--){
		e[d]=w[i];
		d++;
	}
	
	for(int i=1;i<=u;i++){
		if(jl==e[i]){
			j=i;
			break;
		}
	}
	int h,l,t;
	if(j%m==0) l=j/m;
	else{
		l=j/m+1;
	}
	if(l%2==0){
		t=j-(l-1)*m;
		h=m-t+1;
	}
	else{
		h=j-(l-1)*m;
	}
	cout<<l<<' '<<h;
	return 0;
}
