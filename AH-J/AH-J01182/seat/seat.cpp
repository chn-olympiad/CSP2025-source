#include<bits/stdc++.h>
using namespace std;
int x=1,y=1,s=1,n,m,sx,a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sx=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(a[s]!=sx){
		while(x<n){
			if(a[s]==sx){
				cout<<y<<" "<<x;
				return 0;
			}
			x++;
			s++;
		}
		if(a[s]==sx){
			cout<<y<<" "<<x;
			return 0;
		}
		y++;
		s++;
		while(x>1){
			if(a[s]==sx){
				cout<<y<<" "<<x;
				return 0;
			}
			x--;
			s++;
		}
		if(a[s]==sx){
			cout<<y<<" "<<x;
			return 0;
		}
		y++;
		s++;
	}
	cout<<y<<" "<<x;
	return 0;
}
