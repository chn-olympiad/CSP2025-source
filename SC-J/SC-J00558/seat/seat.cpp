#include<bits/stdc++.h>
using namespace std;
bool b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,x,y,s;
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		int l;
		cin>>l;
		b[l]=1;
	}
	for(int i=100;i>r;i--){
		if(b[i]){
			s++;
		}
	}
	s++;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s--;
				if(s==0){
					x=i;
					y=j;
					cout<<x<<" "<<y;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				s--;
				if(s==0){
					x=i;
					y=j;
					cout<<x<<" "<<y;
					return 0;
				}
			}
		}
	}
	return 0;
}