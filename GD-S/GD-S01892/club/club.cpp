#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define ll long long
const int N=2e5+5;
int T,n;
ll ans;
struct node{
	ll num,km,down,p,nxt;
	bool operator < (const node &o)const{
		return num>o.num;
	}
}a[N][4];
struct node1{
	ll num,down,p,nxt;
	bool operator < (const node1 &o)const{
		return down>o.down;
	}
};
priority_queue<node1> q[4];
bool work(int i,int j,int dep){
	if(dep>3) return true;
	node1 t=q[a[i][j].km].top();//找到一个下滑最少的，如果交换后更优则交换
	ll res=ans-t.num;
	if(res+t.num-t.down+a[i][j].num>res+t.num+a[i][j].num-a[i][j].down){
		q[a[i][j].km].pop();
		if(q[t.nxt].size()==n/2){
			if((!work(t.p,t.nxt-1,dep+1)&&t.nxt)||!t.nxt) {
				q[a[i][j].km].push(t);
				return false;
			}
		}
		q[a[i][j].km].push((node1){a[i][j].num,a[i][j].down,a[i][j].p,a[i][j].nxt});
//		p[t.p]=t.nxt;
//		p[i]=a[i][j].km;
		ans=res+t.num-t.down+a[i][j].num;
		return true;
	}return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].num;
				a[i][j].km=j;a[i][j].p=i;
			}sort(a[i]+1,a[i]+4);
			for(int j=1;j<=2;j++){
				a[i][j].down=a[i][j].num-a[i][j+1].num;
				a[i][j].nxt=j+1;
			}
		}
		for(int i=1;i<=3;i++) while(q[i].size())q[i].pop();
		ans=0;
//		vector<int> p(n+1,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(q[a[i][j].km].size()<n/2){
//					p[i]=a[i][j].km;
					ans+=a[i][j].num;
					q[a[i][j].km].push((node1){a[i][j].num,a[i][j].down,a[i][j].p,a[i][j].nxt});
					break;
				}else{
					if(work(i,j,1)){
						break;
					}
				}
			}
		}
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
