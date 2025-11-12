#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5,INF=2e9;
int QwQ,n,cnt[5];
struct NODE{
	int x,y,px,py;
}a[MAXN];
int TT(int tta,int ttb,int ttc,int ttx){
	if (ttx==tta) return 1;
	else if (ttx==ttb) return 2;
	else return 3;
}
int main(){
//	std::ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>QwQ;
	while (QwQ--){
		long long ans=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qa,qb,qc;
		cin>>n;
		for (int i=1;i<=n;i++){
			int ta,tb,tc,mx=0,mn=INF;
			cin>>ta>>tb>>tc;
			mx=max({ta,tb,tc}),mn=min({ta,tb,tc});
			a[i].x=mx,a[i].y=(ta+tb+tc)-mx-mn;
			a[i].px=TT(ta,tb,tc,a[i].x);
			a[i].py=TT(ta,tb,tc,a[i].y);
			//cout<<a[i].x<<' '<<a[i].px<<' '<<a[i].y<<' '<<a[i].py<<'\n';
		}
		for (int i=1;i<=n;i++){
			if (cnt[a[i].px]+1<=n/2){  //可加入，直接加入 
				if (a[i].px==1){
					qa.push({a[i].x,i});
					cnt[1]++;
				}
				else if (a[i].px==2){
					qb.push({a[i].x,i});
					cnt[2]++;
				}
				else{
					qc.push({a[i].x,i});
					cnt[3]++;
				}
				ans=ans+a[i].x;
			}
			else{
				int id=qa.top().second;  //冲突社团中贡献最小的人 
				if (a[id].x+a[i].y>a[i].x+a[id].y){  //不踢出 
					if (a[i].py==1){
						qa.push({a[i].y,i});
						cnt[1]++;
					}
					else if (a[i].py==2){
						qb.push({a[i].y,i});
						cnt[2]++;
					}
					else{
						qc.push({a[i].y,i});
						cnt[3]++;
					}
					ans=ans+a[i].y;
				}
				else{  //踢出
					if (a[id].px==1){
						qa.pop();
						qa.push({a[i].x,i});
					}
					else if (a[id].px==2){
						qb.pop();
						qb.push({a[i].x,i});
					}
					else{
						qc.pop();
						qc.push({a[i].x,i});
					}
					
					if (a[id].py==1){
						cnt[1]++;
						qa.push({a[id].y,i});
					}
					else if (a[id].py==2){
						cnt[2]++;
						qb.push({a[id].y,i});
					}
					else{
						cnt[3]++;
						qc.push({a[id].y,i});
					}
					ans=ans-a[id].x+a[id].y+a[i].x;
				}
			}
		}
		cout<<ans<<'\n';
		for (int i=0;i<5;i++) cnt[i]=0;
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
