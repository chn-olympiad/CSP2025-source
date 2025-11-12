#include<bits/stdc++.h>
using namespace std;
int t,n;
struct Node_min{
	int id,x;
	bool operator <(const Node_min n)const{
		return n.x<this->x;
	}
	bool operator >(const Node_min n)const{
		return n.x>this->x;
	}
};
struct Node{
	Node_min f[5];
	int next(){
		swap(this->f[1],this->f[2]);
		swap(this->f[2],this->f[3]);
		return this->f[1].id;
	}
	bool operator <(const Node n)const{
		if(n.f[1].x!=this->f[1].x) return n.f[1]<this->f[1];
		if(n.f[2].x!=this->f[2].x) return n.f[2]<this->f[2];
		return n.f[3]<this->f[3];
	}
	bool operator >(const Node n)const{
		if(n.f[1].x!=this->f[1].x) return n.f[1]>this->f[1];
		if(n.f[2].x!=this->f[2].x) return n.f[2]>this->f[2];
		return n.f[3]>this->f[3];
	}
}a[500005];
//Node k[3][500005<<2];
//int top[4],last[4];
priority_queue<Node,vector<Node>,greater<Node> > k[4];
long long sum,sumk;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0,sumk=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].f[1].x,&a[i].f[2].x,&a[i].f[3].x);
			a[i].f[1].id=1;a[i].f[2].id=2;a[i].f[3].id=3;
			sort(a[i].f+1,a[i].f+4);
			//printf("%d %d %d\n",a[i].f[1].x,a[i].f[2].x,a[i].f[3].x);
			int id=a[i].f[1].id;
			//if(!k[3].empty()) cout<<k[3].top().f[1].x<<endl;
			B:
			if(int(k[id].size())==n/2){
				Node now=k[id].top();
				//printf("--\n");
//				while(now.f[1].x<=now.f[2].x&&int(k[id].size())>=1){
//sumk+=now.f[1].x;now.f[2].x=-1;
//				now.f[1].x=INT_MAX;
//				k[id].pop();now=k[id].top();}
				if(now.f[2].x+a[i].f[1].x>now.f[1].x+a[i].f[2].x&&now.f[2].x!=-1){
					k[id].pop();
					k[id].push(a[i]);
					//id=a[i].next();
					a[i]=now;
					id=a[i].next();
					goto B;
				}
				else{
					id=a[i].next();goto B;
				}
			}else{
				k[id].push(a[i]);
			}
		}
		for(int j=1;j<=3;j++)
			while(!k[j].empty()){if(k[j].top().f[2].x!=-1)sum+=k[j].top().f[1].x;k[j].pop();}
		printf("%lld\n",sum+sumk);
	}
	return 0;
}
