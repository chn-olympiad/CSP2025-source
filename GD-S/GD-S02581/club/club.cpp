#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> node;
const int N=1e5+10;
const node none={-1e9,-1};
int n,h[N][3],siz[3],ad[N],ans,dt[10]={1,2,0,2,0,1};
node a[10];
priority_queue<node>q[3][3];
node find(int x,int y){
	while(!q[x][y].empty()&&ad[q[x][y].top().y]!=x) q[x][y].pop();
	return(q[x][y].empty()?none:q[x][y].top());
}
void clear(){
	while(q[0][1].size()) q[0][1].pop();
	while(q[1][2].size()) q[1][2].pop();
	while(q[2][0].size()) q[2][0].pop();
	while(q[0][2].size()) q[0][2].pop();
	while(q[1][0].size()) q[1][0].pop();
	while(q[2][1].size()) q[2][1].pop();
}
int delta(int i,int x){
	return h[i][x]-h[i][ad[i]];
}
int find_max(int a,int b,int c,int d,int e,int f){
	if(a>b)
		if(a>c)
			if(a>d)
				if(a>e)
					if(a>f) return 1;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
			else
				if(d>e)
					if(d>f) return 4;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
		else
			if(c>d)
				if(c>e)
					if(c>f) return 3;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
			else
				if(d>e)
					if(d>f) return 4;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
	else
		if(b>c)
			if(b>d)
				if(b>e)
					if(b>f) return 2;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
			else
				if(d>e)
					if(d>f) return 4;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
		else
			if(c>d)
				if(c>e)
					if(c>f) return 3;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
			else
				if(d>e)
					if(d>f) return 4;
					else return 6;
				else
					if(e>f) return 5;
					else return 6;
}
void push(int x,int y){
	ad[x]=y;
	for(int i=y*2;i<=y*2+1;i++){
		q[y][dt[i]].push({delta(x,dt[i]),x});
	}
}
void solve(){
	clear();
	cin>>n;
	siz[0]=n,siz[1]=siz[2]=0;
	ans=0;
	for(int i=1;i<=n;i++){
		ad[i]=0;
		cin>>h[i][0]>>h[i][1]>>h[i][2];
		ans+=h[i][0];
		q[0][1].push({delta(i,1),i});
		q[0][2].push({delta(i,2),i});
	}
	while(siz[0]>n/2){
		siz[0]--;
		node u=find(0,1),v=find(0,2);
		if(u.x>v.x){
			int i=u.y;
			ans+=u.x;
			ad[i]=1;
			siz[1]++;
			push(i,1);
			q[0][1].pop();
			continue;
		}
		if(u.x<v.x){
			int i=v.y;
			ans+=v.x;
			ad[i]=2;
			siz[2]++;
			push(i,2);
			q[0][2].pop();
			continue;
		}
	}
	while(1){
		a[0]=find(0,1),a[1]=find(0,2);
		a[2]=find(1,0),a[3]=find(1,2);
		a[4]=find(2,0),a[5]=find(2,1);
		int p=find_max(a[0].x,a[1].x,a[2].x,a[3].x,a[4].x,a[5].x)-1;
		if(a[p].x<=0) break;
		int dir=dt[p];
		q[p/2][dir].pop();
		
		if(siz[dir]==n/2){
			if(a[dir*2].x>a[dir*2+1].x){
				if(a[dir*2].x+a[p].x>0)
					q[dir][dt[dir*2]].pop(),
					push(a[dir*2].y,dt[dir*2]),push(a[p].y,dir),
					ans+=a[dir*2].x+a[p].x,siz[dt[dir*2]]++,siz[p/2]--;
			}
			else{
				if(a[dir*2+1].x+a[p].x>0)
					q[dir][dt[dir*2+1]].pop(),
					push(a[dir*2+1].y,dt[dir*2+1]),push(a[p].y,dir),
					ans+=a[dir*2+1].x+a[p].x,siz[dt[dir*2+1]]++,siz[p/2]--;
			}
		}
		else ans+=a[p].x,siz[p/2]--,siz[dir]++,push(a[p].y,dir);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
/*
1 4
1 4 5
1 2 5
1 1 5
1 2 4
*/
