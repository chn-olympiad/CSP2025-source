#include<bits/stdc++.h>
using namespace std;

int T,n,ntoo,ans;
struct O{
	int love,di;
}f[100005][5];
bool cmp(O a,O b){
	return a.love>b.love;
}
struct point{
	int cha,id,num;
	bool operator < (const point &b)const{
		return cha > b.cha;
	}
};
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		priority_queue<point> q[3];
		cin>>n;ntoo=n/2;ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				cin>>f[i][j].love;
				f[i][j].di=j;
			}sort(f[i]+0,f[i]+3,cmp);
		}
		for(int i=1;i<=n;i++){
			O now=f[i][0];
			if(q[now.di].size()<ntoo){
				q[now.di].push({now.love-f[i][1].love,i,now.love});
			}else{
				if(now.love-f[i][1].love>=q[now.di].top().cha){
					int new_id=q[f[i][0].di].top().id;
					q[f[new_id][1].di].push({f[new_id][1].love-f[new_id][2].love,new_id,f[new_id][1].love});
					q[now.di].pop();
					q[now.di].push({now.love-f[i][1].love,i,now.love});
				}else{
					q[f[i][1].di].push({f[i][1].love-f[i][2].love,i,f[i][1].love});
				}
			}
		}
		for(int i=0;i<=2;i++){
			while(!q[i].empty()){
				ans+=q[i].top().num;
				q[i].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
