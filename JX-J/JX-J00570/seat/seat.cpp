#include<bits/stdc++.h>
using namespace std;
int a[150],ton[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int op;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			op=a[i];
		}
		ton[a[i]]=true;
	}
	int w=-1;
	for(int i=100;i>=op;i--){
		if(ton[i]){
			w++;
		}
	}
	int x=1,y=1;
	while(w--){
		if(x==n&&y&1){
			y++;
		}else if(x==1&&!(y&1)){
			y++;
		}else if(!(y&1)){
			x--;
		}else{
			x++;
		}
		
	}
	cout<<y<<" "<<x;
	return 0;
}
