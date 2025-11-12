#include<bits/stdc++.h>
using namespace std;
int sc[111];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b;
	cin>>a>>b;
	int p0 = a*b;
	int si = 0;
	for(int i = 1;i <= p0;i++){
		cin>>sc[i];
	}
	si = sc[1];
	sort(sc+1,sc+1+p0,cmp);
	int xx = 1,yy = 1;
	int dx = 1,dy = 0;
	for(int i = 1;i <= p0;i++){
		if(sc[i] == si){
			cout<<yy<<' '<<xx;
			return 0;
		}
		if(xx == a && (dx == 1&&dy == 0) ){
			dx = 0,dy = 1;
		}else if(xx == a && (dx == 0&&dy == 1)){
			dx = -1,dy = 0;
		}else if(xx == 1 && (dx == -1&&dy == 0)){
			dx = 0,dy = 1;
		}else if(xx == 1 && (dx == 0&&dy == 1)){
			dx = 1,dy = 0;
		}
		xx += dx;
		yy += dy;
	}
	return 0;
} 
