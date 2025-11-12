#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;
struct node{
	int d[7],maxx1,maxx2;
}qwq[maxn];
struct node2{
	int W,id;
	bool operator<(const node2 &B)const{
		return W>B.W;
	}
};
struct node3{
	int ID,Z;
};
int n;
priority_queue<node2>pq[7];
bool cmp(node3 qa,node3 qb){
	return qa.Z>qb.Z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			node3 op[7];
			cin>>qwq[i].d[1]>>qwq[i].d[2]>>qwq[i].d[3];
			op[1].Z=qwq[i].d[1];
			op[1].ID=1;
			op[2].Z=qwq[i].d[2];
			op[2].ID=2;
			op[3].Z=qwq[i].d[3];
			op[3].ID=3;
			sort(op+1,op+4,cmp);
			qwq[i].maxx1=op[1].ID;
			qwq[i].maxx2=op[2].ID;
		}
		for(int i=1;i<=n;i++){
			int nowid=qwq[i].maxx1;
			pq[nowid].push(node2{qwq[i].d[qwq[i].maxx1]-qwq[i].d[qwq[i].maxx2],i});
			if(pq[nowid].size()>(n/2)){
				int op=pq[nowid].top().id;
				int pid=qwq[op].maxx2;
				pq[pid].push(node2{20110203,op});
				pq[nowid].pop();
			}
		}
		int ans=0;
		while(!pq[1].empty()){
			int op=pq[1].top().id;
//			cout<<"1: "<<op<<endl;
			ans+=qwq[op].d[1];
			pq[1].pop();
		}
		while(!pq[2].empty()){
			int op=pq[2].top().id;
//			cout<<"2: "<<op<<endl;
			ans+=qwq[op].d[2];
			pq[2].pop();
		}
		while(!pq[3].empty()){
			int op=pq[3].top().id;
//			cout<<"3: "<<op<<endl;
			ans+=qwq[op].d[3];
			pq[3].pop();
		}
		cout<<ans<<endl;
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

*/
