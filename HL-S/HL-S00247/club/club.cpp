#include<bits/stdc++.h>
using namespace std;
int t,n,a[114514][4],p[4],maxn;
struct Node{
	int s;
	int num;
};
void c(){
	queue<Node> q;
	maxn=-1;
	memset(p,0,sizeof(p)); 
	Node h;
	h.s=0;
	h.num=0;
	q.push(h); 
	while(!q.empty()){
		Node cur=q.front();
		for(int i=1;i<=3;i++){
			if(p[i]>=(n/2))	continue; 
			Node ns;
			ns.s=cur.s+1;
			ns.num=cur.num+a[ns.s][i];
			maxn=max(maxn,ns.num);
			p[i]++;  
			q.push(ns);
			p[i]--;
		}
		if(q.front().s==n){	
			cout<<maxn;
			return;
		}	
		q.pop();
	}
	return;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)	cin>>a[i][j];
		}	
		c();	
	}
	fclose(stdin);
	fclose(stdout);
} 
