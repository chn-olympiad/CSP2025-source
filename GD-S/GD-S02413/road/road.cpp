#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7,M=2e6+7,K=15;
int n,m,k,l[N+K],len,qlen;
long long c[K],cw[K][N],bc[K];
long long res;

struct Node{
	int a,b,f;
	long long w;
	bool operator<(const Node&p)const{
		return w<p.w;
	}bool operator>(const Node&p)const{
		return w>p.w;
	}
};
priority_queue<Node,vector<Node>,less<Node> > q;
priority_queue<Node,vector<Node>,greater<Node> > resq;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	
	const int LIMIT=n;
	
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c,q.push({a,b,0,c}),qlen++;
		if(qlen>LIMIT)	q.pop(),qlen--;
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cw[i][j];
		}
	}
	while(!q.empty()){
		resq.push(q.top()),q.pop();
	}int idx=1,r=n-1;Node t;
	vector<Node> TRASH;
	while(len<r){
		Node t=resq.top();resq.pop();
		if(l[t.a]==0||l[t.b]==0){
			res+=t.w,len++;
			l[t.a]=l[t.b]=1;
		}
	}cout<<res<<endl;
	
	fclose(stdin);
	fclose(stdout);
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 5 0
1 2 1
1 3 2
1 4 3
2 3 5
2 4 2

SB代码莫名其妙就直接size变0了啊！！！！！！！！！虽然这样写没啥用 
算了让这货退化得了 
*/
