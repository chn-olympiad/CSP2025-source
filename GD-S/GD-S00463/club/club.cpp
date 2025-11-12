#include<bits/stdc++.h>
using namespace std;
int com(int a,int b,int c){
	if((a>b||a>c)&&(a<b||a<c)) return 0;
	else if((b>a||b>c)&&(b<a||b<c)) return 1;
	else return 2;
}
int vcom(int a,int b,int c){
	if((a>b||a>c)&&(a<b||a<c)) return a;
	else if((b>a||b>c)&&(b<a||b<c)) return b;
	else return c;
}
struct Node{
	int a,b,c;
	int mid=com(a,b,c),maxn=max(a,max(b,c));
	int vmid=vcom(a,b,c);
	bool operator<(const Node &s)const{
		return s.maxn-s.vmid<maxn-vmid;
	}
};
int Q;
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&Q);
	while(Q--){
		priority_queue<Node>q[3];
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			int maxn=max(a,max(b,c));
			if(maxn==a){
				q[0].push({a,b,c});
				if(q[0].size()>n/2){
					Node t=q[0].top();
					q[0].pop();
					q[t.mid].push(t); 
				}
			}else if(maxn==b){
				q[1].push({a,b,c});
				if(q[1].size()>n/2){
					Node t=q[1].top();
					q[1].pop();
					q[t.mid].push(t);
				}
			}else{
				q[2].push({a,b,c});
				if(q[2].size()>n/2){
					Node t=q[2].top();
					q[2].pop();
					q[t.mid].push(t);
				}
			}
		}
		long long sum=0;
		while(!q[0].empty()){
			sum+=q[0].top().a;
			q[0].pop();
		}
		while(!q[1].empty()){
			sum+=q[1].top().b;
			q[1].pop();
		}
		while(!q[2].empty()){
			sum+=q[2].top().c;
			q[2].pop();
		}
		printf("%lld\n",sum);
	}
	return 0;
}

