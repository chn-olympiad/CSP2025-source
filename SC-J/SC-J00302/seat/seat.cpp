#include "bits/stdc++.h"
using namespace std;
int a[1010];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int x=1,y=1,l=m*n;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	
	int score=a[1];
	sort(a+1,a+l+1,cmp);
	
	
	int fd;
	for(int i=1;i<=l;i++){
		if(score==a[i]){
			fd=i;
			
			
			break;
		}
	}
	
	for(int i=1;i<fd;i++){
		if(x%2==0){
			y--;
			if(y<1){
				x++;
				y++;
			}
		}else{
			y++;
			if(y>n){
				x++;
				y--;
			}
		}
	}
	
	cout<<x<<" "<<y;
	return 0;
} 