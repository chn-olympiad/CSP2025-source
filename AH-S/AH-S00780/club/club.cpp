#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z;
	int c;
}a[100005];
int sx,sy,sz;
long long ans;
bool cmp1(node g,node h){
	return min(g.x-g.y,g.x-g.z)<min(h.x-h.y,h.x-h.z);
}
bool cmp2(node g,node h){
	return min(g.y-g.x,g.y-g.z)<min(h.y-h.x,h.y-h.z);
}
bool cmp3(node g,node h){
	return min(g.z-g.x,g.z-g.y)<min(h.z-h.x,h.z-h.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>t;
	while(t--){
		sx=0,sy=0,sz=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z)ans+=a[i].x,sx++,a[i].c=1;
			else if(a[i].y>=a[i].x && a[i].y>=a[i].z)ans+=a[i].y,sy++,a[i].c=2;
			else if(a[i].z>=a[i].x && a[i].z>=a[i].y)ans+=a[i].z,sz++,a[i].c=3;
		}
		if(sx>n/2){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;sx>n/2;i++){
				if(a[i].c!=1)continue;
				if(a[i].y>a[i].z)ans=ans-a[i].x+a[i].y,sy++,a[i].c=2;
				else ans=ans-a[i].x+a[i].z,sz++,a[i].c=3;
				sx--;
			}
		}
		if(sy>n/2){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;sy>n/2;i++){
				if(a[i].c!=2)continue;
				if(a[i].x>a[i].z)ans=ans-a[i].y+a[i].x,sx++,a[i].c=1;
				else ans=ans-a[i].y+a[i].z,sz++,a[i].c=3;
				sy--;
			}
		}
		if(sz>n/2){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;sz>n/2;i++){
				if(a[i].c!=3)continue;
				if(a[i].x>a[i].y)ans=ans-a[i].z+a[i].x,sx++,a[i].c=1;
				else ans=ans-a[i].z+a[i].y,sy++,a[i].c=2;
				sz--;
			}
		}if(sx>n/2 || sy>n/2 || sz>n/2)cout<<'?';if(sx+sy+sz!=n)cout<<'!';
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
