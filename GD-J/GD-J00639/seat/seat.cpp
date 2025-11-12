#include<bits/stdc++.h>
using namespace std;
int rankk[105];

bool cmp(int x1,int x2){
	return x1>x2; 
}
int main(){
	int n,m,r;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>rankk[i];
		if(i==1){
			r=rankk[i];
		}
	}
	sort(rankk+1,rankk+n*m+1,cmp);
	int x,y;
	for(int i=1;i<=n*m;i++){
		if(rankk[i]==r){
			
			y=i/n;
			if(y*n!=i){
				y++;
			}
			x=i%(2*n);
			if(x>n){
				x=(2*n)-x+1;
			}
			if(x==0){
				x=1;
			}
		}
		
	}
	cout<<y<<" "<<x<<endl;
	
	return 0;
} 
