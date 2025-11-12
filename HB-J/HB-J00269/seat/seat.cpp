#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])pos++;
	}
	int x=1,y=1,p=1;
	bool dir=0;
	while(y<=m){
		if(p==pos){
			cout<<y<<" "<<x;
			return 0;
		}p++;
		if(dir==0){
			if(x==n){
				y++;
				dir=1;
			}else{
				x++;
			}
		}else{
			if(x==1){
				y++;
				dir=0;
			}else{
				x--;
			}
		}
	}
	return 0;
}
