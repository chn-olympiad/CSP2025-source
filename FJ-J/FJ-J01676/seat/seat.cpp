#include<bits/stdc++.h>
using namespace std;
int n,m,r,w=1,w1,w2,a[110],x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]>r) w++;
	}
	w1=w%n;
	w2=w/n;
	if(w2%2==0){
		x=w2;
		y=1;
		if(w1==0) cout<<x<<" "<<y;
		if(w1==1){
			x++;
			cout<<x<<" "<<y;
		}
		if(w1>1){
			x++;
			y+=w1-1;
			cout<<x<<" "<<y;
		}
		return 0;
	}
	if(w2%2==1){
		x=w2;
		y=n;
		if(w1==0) cout<<x<<" "<<y;
		if(w1==1){
			x++;
			cout<<x<<" "<<y;
		}
		if(w1>1){
			x++;
			y-=w1-1;
			cout<<x<<" "<<y;
		}
		return 0;
	}
	return 0;
}