#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l,o,p;
void q(int x,int y,int s,bool v,bool v1){
	if(a[s]==l){
		p=x;
		o=y;
		return;
	}
	if(v==true){
		if(v1==false) q(x+1,y,s-1,false,false);
		else q(x-1,y,s-1,false,true);
	}else if(x==n){
		q(x,y+1,s-1,true,true);
	}else if(x==1){
		q(x,y+1,s-1,true,false);
	}else if(v1==false){
		q(x+1,y,s-1,false,false);
	}else{
		q(x-1,y,s-1,false,true);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+t+1);
	q(1,1,t,true,false);
	cout<<o<<" "<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
