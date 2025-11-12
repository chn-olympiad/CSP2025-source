#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*f;
}
constexpr int N=1e5+5;
int q[N][4];
struct node{
	ll v;
	int idx,i;
	bool operator <(const node &a)const{
		/*if(v==a.v){
			return q[idx][i+1]>q[a.idx][a.i+1];
		}*/
		return q[idx][i]-q[idx][i+1]>q[a.idx][a.i]-q[a.idx][a.i+1];
	}
};

set<pair<int,int>> t;

int idx[N][3];
priority_queue<node> p[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cout.tie(0);
	int T=read(),n;
	ll ans=0;
	node temp;
	while(T--){
		n=read(),ans=0;
		for(int i=1;i<=n;i++){
			q[i][0]=read(),q[i][1]=read(),q[i][2]=read();
			t.insert({q[i][0],0}),t.insert({q[i][1],1}),t.insert({q[i][2],2});
			ans=3;
			for(auto &j:t){
//				cout<<j.first<<" "<<ans-1<<" ? ";
				q[i][--ans]=j.first;
				idx[i][ans]=j.second;
			}
//			cout<<"\n";
//			p[idx[i][0]].push({q[i][0],i,0});
//			cout<<i<<" in "<<idx[i][0]<<"\n";
			t.clear();
		}
		//idx[i][0]:{q[i][0],i,0};
//		return 0;
		ans=0;
		//q[i][j] i的第j大 idx[i][j] i的第j顺位选择 
		for(int i=1;i<=n;i++){
			if(p[idx[i][0]].size()<n/2){
				p[idx[i][0]].push({q[i][0],i,0});
//				cout<<"A\n";
			}else{
				temp=p[idx[i][0]].top();//q[temp.idx][temp.i+1]
				if(q[temp.idx][temp.i+1]+q[i][0]>q[temp.idx][temp.i]+q[i][1]){
					p[idx[temp.idx][temp.i+1]].push({q[temp.idx][temp.i+1],temp.idx,temp.i});
					p[idx[i][0]].pop();
					p[idx[i][0]].push({q[i][0],i,0});
//					cout<<"B\n";
				}else{
					p[idx[i][1]].push({q[i][1],i,1});
//					cout<<"C\n";
				}
			}
//			cout<<p[idx[i][0]].size()<<"?\n";
		}
		/*for(int j=0;j<=2;j++){
			while(p[j].size()>n/2){
				node k=p[j].top();
				p[idx[k.idx][k.i+1]].push({q[k.idx][k.i+1],k.idx,k.i+1});
				p[j].pop();
//				cout<<"trans: "<<idx[k.idx][k.i]<<" (is "<<k.idx<<") to "<<idx[k.idx][k.i+1]<<"\n";
			}
		}*/
		for(int j=0;j<=2;j++){
			while(!p[j].empty()){
				ans+=p[j].top().v;
				p[j].pop();
			}
		}
		cout<<ans<<"\n";
	}
}
