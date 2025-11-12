#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int t,stf[N][4];
priority_queue<int> c[4];
void update(){
	for(int i=0;i<N;i++){
		for(int j=0;j<=3;j++){
			stf[i][j]=0;
		}
	}
	for(int i=0;i<4;i++){
		while(!c[i].empty()){
			c[i].pop();
		}
	}
	return;
}
int mxid(int x){
	int mx=max(stf[x][1],stf[x][2]),id;
	if(stf[x][1]==mx) id=1;
	else id=2;
	if(stf[x][3]>mx){
		return 3;
	}else return id;
}
int f(int x,int id){
	if(id==1) return max(stf[x][2],stf[x][3]);
	else if(id==2) return max(stf[x][1],stf[x][3]);
	else return max(stf[x][1],stf[x][2]);
}
void solve(){
	cin>>t;
	while(t--){
		update();
		int n,cnt[4]={},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>stf[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int k=mxid(i),mx=f(i,k);
			if(cnt[k]<n/2){
				ans=ans+stf[i][k];
				c[k].push(mx-stf[i][k]);
				cnt[k]++;
			}else{
				if(stf[i][k]+c[k].top()>mx){
					ans=ans+stf[i][k]+c[k].top();
					c[k].pop();
					c[k].push(mx-stf[i][k]);
				}else ans+=mx;
			}
		}
		cout<<ans<<endl;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	solve();
	return 0;
}
