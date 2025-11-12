#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,fen[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>fen[i];
	}
	int rf=fen[1],gao=1;
	for(int i=2;i<=n*m;i++){
		if(fen[i]>rf){
			gao++;
		}
	}
	int x=gao/n,y;
	if(gao%n!=0){
		x+=1;
	}
	if(x%2==1){
		if(gao%n==0){
			y=n;
		}else{
			y=gao%n;
		}
    }else{
    	y=n-gao%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
