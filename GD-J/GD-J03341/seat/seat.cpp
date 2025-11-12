#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n=0,m=0,r,q[101]={0},cnt=0,rx=0,ry=0;
	cin >> n >> m;
	int gs[m*n];
	for(int i=0;i<n*m;i++){
		cin >> gs[i];
		q[gs[i]]=1;
	}
	r=gs[0];
	for(int j=100;j>=r;j--){
        if(q[j]==1){
            cnt++;
        }
	}
	int fcnt=(cnt+n-1)/n;

	if(fcnt%2==1){
        rx=fcnt;
        if(cnt%n!=0){
            ry=cnt%n;
        }else{ry=n;}
	}else{
	    rx=fcnt;
	    if(cnt%n!=0){
            ry=n-cnt%n+1;
	    }else{ry=1;}
	}
	cout << rx <<" "<< ry;
	return 0;
}
