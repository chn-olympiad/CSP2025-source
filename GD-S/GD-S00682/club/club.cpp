#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
struct Pair{
	int fir,sec;
	bool operator<(const Pair p)const{return fir>p.fir;}
};
int t,n,v[N][5],rk[N],ans;
Pair a[N][5];
priority_queue<Pair>q[5];
void solve(int x){
	int i=++rk[x];
	int d=a[x][i].sec,d2=a[x][i+1].sec;
	q[d].push({v[x][d]-v[x][d2],x});
	ans+=v[x][d];
	if(q[d].size()>n/2){
		int k=q[d].top().sec;
		q[d].pop();
		ans-=v[k][d];
		solve(k);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(rk,0,sizeof(rk));
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i][1]>>v[i][2]>>v[i][3];
			a[i][1]={v[i][1],1};
			a[i][2]={v[i][2],2};
			a[i][3]={v[i][3],3};
			sort(a[i]+1,a[i]+4);
			solve(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
