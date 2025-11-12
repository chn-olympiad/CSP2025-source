//14 34 5/5 100pts
//4mb
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
int a[N][3];
struct node{
	int val,id;
	bool type;
	bool operator<(const node &o)const{
		return val<o.val;
	}
};
priority_queue<node> q0,q1,q2;
void clq(){
	priority_queue<node> t0;
	swap(q0,t0);
	priority_queue<node> t1;
	swap(q1,t1);
	priority_queue<node> t2;
	swap(q2,t2);
	return;
}
int help(){
	clq();
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			q0.push({max(a[i][1],a[i][2])-a[i][0],i,false});
			ans+=a[i][0];
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			q1.push({max(a[i][0],a[i][2])-a[i][1],i,false});
			ans+=a[i][1];
		}
		else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
			q2.push({max(a[i][0],a[i][1])-a[i][2],i,false});
			ans+=a[i][2];
		}
	}
	while(q0.size()>n/2){
		node cur=q0.top();
		q0.pop();
		int val=cur.val,id=cur.id;
		ans+=val;
		if(a[id][1]>=a[id][2]){
			q1.push({a[id][2]-a[id][1],id,true});
		}
		else{
			q2.push({a[id][1]-a[id][2],id,true});
		}
	}
	while(q1.size()>n/2){
		node cur=q1.top();
		q1.pop();
		int val=cur.val,id=cur.id;
		bool type=cur.type;
		if(q0.size()==n/2&&!type){
			q1.push({a[id][2]-a[id][1],id,true});
			continue;
		}
		ans+=val;
		if(q0.size()==n/2){
			q2.push({a[id][0]-a[id][2],id,true});
		}
		else{
			if(a[id][0]>=a[id][2]){
				q0.push({a[id][2]-a[id][0],id,false});
			}
			else{
				q2.push({a[id][0]-a[id][2],id,false});
			}
		}
	}
	while(q2.size()>n/2){
		node cur=q2.top();
		q2.pop();
		int val=cur.val,id=cur.id;
		bool type=cur.type;
		if(q0.size()==n/2&&!type){
			q2.push({a[id][1]-a[id][2],id,true});
			continue;
		}
		else if(q1.size()==n/2&&a[id][0]!=a[id][1]&&val==a[id][1]-a[id][2]){
			q2.push({a[id][0]-a[id][2],id,false});
			continue;
		}
		ans+=val;
		//no meaning to push anything
		//(bad english)
	}
	//why this can work?
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cout<<help()<<endl;
	}
	return 0;
}
//ccf help me please!
//0.9521 seconds! `for(;;)++rp;`!
