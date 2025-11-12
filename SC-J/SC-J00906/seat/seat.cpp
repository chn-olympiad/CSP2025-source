#include<bits/stdc++.h>
using namespace std;
int p[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
		if(i==1) t=p[1];
	} 
	sort(p+1,p+n*m+1);
	int q=n*m,x=1,y=1;
	while(q>=1){
		if(y%2==1){
			if(x<1) x++;
			while(x<=n){
				if(p[q]==t){
					cout<<y<<" "<<x;
					return 0; 
				}
				q--;
				x++;
			}
		}else{
			if(x>n) x--;
			while(x>=1){
				if(p[q]==t){
					cout<<y<<" "<<x;
					return 0; 
				}
				q--;
				x--;
			}
		}
		y++;
	}
	
	return 0;
} 