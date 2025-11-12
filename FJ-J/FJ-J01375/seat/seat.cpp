#include<bits/stdc++.h>
using namespace std;
bool f(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,g[1005];
	cin>>n>>m;
	int s=n*m,R=0;
	for(int i=1;i<=s;i++){
		cin>>g[i];
	}
	R=g[1];
	if(R==100){
		cout<<1<<" "<<1;
		return 0;
	}
	sort(g,g+s,f);
	for(int i=1;i<=s;i++){
		if(g[i]==R){
			R=i;
			break;
		}
	}
	if(R==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int c,r;
	if(R%n==0){
		r=R/n;
		if(R/n%2==0){
			c=R-(R/n*n)+1;
		}else{
			c=R-((R/n-1)*n);
		}
	}else{
		r=R/n+1;
		if((R/n+1)%2==0){
			c=R-(R/n*n)+1;
		}else{
			c=R-((R/n-1)*n);
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
