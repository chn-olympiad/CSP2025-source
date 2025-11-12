#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105],rank,seat[15][15];
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	rank=a[1]; 
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		seat[x][y]=a[i];
		if(x<n&&y%2==1)
			x++;
		else if(x>1&&y%2==0)
			x--;
		else if(x==n||x==1)
			y++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==rank){
				cout<<j<<' '<<i;
				return 0; 
			}
		}
	}
	return 0;
}
//csp-s rp++
/*
RRRRRRR        PPPPPPP
RRRRRRRRR      PPPPPPPPP
RR     RR      PP	  PP	++	   ++	
RR     RR	   PP     PP	++     ++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRR 		   PP			++     ++
RRRRR		   PP			++     ++
RR RRR		   PP	
RR  RRR		   PP
RR   RRR	   PP
RR    RRR 	   PP 
*/ 
