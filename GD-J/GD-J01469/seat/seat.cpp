#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],RExam,c,r,seat[15][15],RSeatX,RSeatY;
const int x0[4]={-1,0,1,0},y0[4]={0,1,0,-1};
int bts(int p,int q){
	return p>q;
}
void OKSeat(int x,int y,int d,int s){
	if(a[s]==RExam){
		RSeatX=x;
		RSeatY=y;
		return;
	}
	if(x+x0[d]<1||x+x0[d]>n){
		OKSeat(x,y+1,1,s+1);
	}else if(d==1){
		if(x==n){
			OKSeat(x-1,y,0,s+1);
		}else if(x==1){
			OKSeat(x+1,y,2,s+1);
		}
	}else{
		OKSeat(x+x0[d],y+y0[d],d,s+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	RExam=a[1];
	sort(a+1,a+n*m+1,bts);
	OKSeat(1,1,2,1);
	cout<<RSeatY<<" "<<RSeatX;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

