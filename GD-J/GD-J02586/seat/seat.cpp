#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,k,d=0,x=1,y=1,a1;
int dy[2]={1,-1};
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n>>a1;
	for(i=1;i<n*m;i++){
		cin>>k;
		s[k]++;
	}
	k=101;
	d=0;
	while(k--){
		for(i=1;i<=s[k];i++){
			if(y+dy[d]>=1&&y+dy[d]<=n){
				y+=dy[d];
			}
			else{
				x++;
				d=(d+1)%2;
			}
		}
		if(a1>=k){
			cout<<x<<" "<<y;
			return 0;
		}
	}
}
