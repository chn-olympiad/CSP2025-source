#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int dx[]={0,1,0,-1,0},dy[]={0,0,1,0,-1};
int a[N][N];
int c[110];
int n,m;
bool cmp(int al,int bl){
	return al>bl;
}
bool pdvis(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0) return 0;
		}
	}
	return 1;
}
queue<pair<int,int>> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(a,0,sizeof(a));
	//memset(vis,0,sizeof(vis));
	cin>>n>>m;
	if(n==1&&m==1){
		int x;cin>>x;
		cout<<x;return 0;
	}
	int xr;cin>>xr;c[1]=xr;
	for(int i=2;i<=n*m;i++){
		cin>>c[i];
	}
	sort(c+1,c+n*m+1,cmp);
	int fw=1;
	q.push(make_pair(1,1));
	a[1][1]=c[1];//zz
	int zz=2;
	while(!q.empty()){
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		if(fw==1){
			if(zz>n*m) break;
			int fx=xx+dx[1],fy=yy+dy[1];
			int flag=1;
			if(fx<1||fx>n||fy<1||fy>m){
				fw=fw+1;
			if(fw>4) fw-=4;
			flag=0;
				q.push(make_pair(xx,yy));//again
			}
			if(flag) a[fx][fy]=c[zz++];
			if(pdvis()) break;
			if(flag) q.push(make_pair(fx,fy));
			continue;
			//转弯时不走 
		}
		 else if(fw==2){//tp
			if(zz>n*m) break;
			int fx=xx+dx[2],fy=yy+dy[2];
			fw=fw+1;
			if(fw>4){
				fw-=4;
			} 
			//flag=0;
			a[fx][fy]=c[zz++];
			if(pdvis()) break;
			q.push(make_pair(fx,fy));
			continue;
		}
		
		else if(fw==3){//tl
			if(zz>n*m) break;
			int fx=xx+dx[3],fy=yy+dy[3];
			int flag=1;
			if(fx<1||fx>n||fy<1||fy>m){
				fw=fw+1;
			if(fw>4) fw-=4;
			flag=0;
			q.push(make_pair(xx,yy));
			}
			if(flag) a[fx][fy]=c[zz++];
			if(pdvis()) break;
			if(flag)q.push(make_pair(fx,fy));
			continue;
		}
		 else if(fw==4){//tp
			if(zz>n*m) break;
			int fx=xx+dx[2],fy=yy+dy[2];
			fw=fw+1;
			if(fw>4){
				fw-=4;
			} 
			a[fx][fy]=c[zz++];
			if(pdvis()) break;
			q.push(make_pair(fx,fy));
			continue;
		}
	}
	//-----------------------------------//
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==xr){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
