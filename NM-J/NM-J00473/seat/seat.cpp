#include <bits/stdc++.h>
using namespace std;
int b[10000],w[10000];
int n,m,p,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	b[0]=p;
	for(int i=1;i<n*m;i++){
		cin>>b[i];
	} 
	sort(b,b+n*m);
	int k=n*m-1; 
	for(int i=0;i<n*m;i++){
		w[k]=b[i];
		k--;
	}
	x=1;
	y=1;
	for(int i=0;i<n*m;i++){
		if(w[i]==p){
			cout<<x<<" "<<y;
		}
		if(y==n){
			x++;
			y=1;
		}else{
			y++;
		}
		
		
	}
	return 0;
}
