#include<bits/stdc++.h>
using namespace std;
int s[102],h,l,n,m,cnt=1,t;
int main(void){
	//freopen
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=0;i<k;++i){
		cin>>s[i];
		if(i!=0&&s[i]>s[0]){
			cnt++;
		}
	}
	t=cnt%(2*n);
	if(t>n&&t<2*n){
		h=2*n-t+1;l=(cnt-t)/n+2;
	}
	else if(t<n&&t>0){
		l=(cnt-t)/n+1;h=t;
	}
	else if(t==n){
		l=(cnt-t)/n+1;h=t;
	}
	else if(t==0){
		l=cnt/n;h=1;
	}
	cout<<l<<' '<<h<<endl;
	return 0;
}
//09:08start 09:23debug start 09:37ok
//
//                RRRRRRR       PPPPPPP      	+ 		  +
//                R      R      P      P		+		  +
//                R      R      P	   P	  +++++ 	+++++
//                RRRRRRR 		PPPPPPP			+		  +
//                RR			P				+		  +
//                R R			P
//                R  R			P
//                R   R			P
//                R    RR		P
