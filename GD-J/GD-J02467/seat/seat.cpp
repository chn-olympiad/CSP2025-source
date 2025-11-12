#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1;
	cin>>n>>m;
	int x;
	for(int i=1;i<=m*n;i++){
		while(x[0]<=x[i]){
			r+=1;
			if(r==n){
				c+=1;
			}
		}
		cout<c<<" "<<r;
	}
	return 0;
}
