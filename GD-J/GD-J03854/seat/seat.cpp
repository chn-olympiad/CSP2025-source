#include<bits/stdc++.h>
using namespace std;
struct gg{
	int a,b;
}h[100100];
bool bb(gg x,gg y){
	return x.a>y.a;
}
int n,m,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>h[i].a;
		h[i].b=i;
	}
	sort(h+1,h+1+n*m,bb);
	for(int i=1;i<=n*m;i++){
		if(h[i].b==1){
			k=i;
			break;
		}
	}
	int u;
	if(k%n==0){
		u=k/n;
	}else{
		u=k/n+1;
	}
	int u2;
	if(u&1==1){
	    u2=k%n;
		if(u2==0){
			u2=n;
		}    
	}else{
		int j=k%n;
		if(j==0){
			j=n;
		}		
		u2=n-j+1;
	}
	cout<<u<<" "<<u2;
	return 0;
} 
