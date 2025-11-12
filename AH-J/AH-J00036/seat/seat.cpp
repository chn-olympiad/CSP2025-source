#include<bits/stdc++.h>
using namespace std;
int n,m,s,a,t,x=1,y;
bool pd;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0) cin>>a;
			else{
				cin>>t;
				if(t>a) s++;
			}
		}
	}
	while(s>=n){
		s-=n;
		pd=!pd;
		x++;
	}
	if(!pd){
		y=1;
		while(s>0){
			s--;
			y++;
		}
		cout<<x<<' '<<y;
	
	}
	else{
		y=n;
		while(s>0){
			s--;
			y--;
		}
		cout<<x<<' '<<y;
	}
	return 0;
}
/*
                    ^
                   /.\
                   \./
                   /|\
                   |||
                   /!\
                  ||!||
                  | ! |
                    !
                    !
                    !
                    !
                    !
                    !
                    !
                    +
*/
